/*
 * Map.cpp
 */

#include "Map.h"
#include "ConfigurationManager.h"
#include "lodepng.h"
#include <iostream>
#include <fstream>


using namespace std;

std::vector<unsigned char> imageArray; //the raw pixels
unsigned int nWidth, nHeight;




//Decode from disk to raw pixels with a single function call
void Map::lodeImage(const char* filename)
{
	//decode
	unsigned error = lodepng::decode(imageArray, nWidth, nHeight, filename);

	//if there's an error, display it
	if (error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

	//the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
}

int Map::GetPositionAsMatrix(int nRow, int nCol)
{
	return (imageArray[nRow * nWidth * 4 + nCol * 4]);
}
void Map::SetPositionAsMatrix(int nRow, int nCol, int nValue)
{
	imageArray[nRow * nWidth * 4 + nCol * 4] = nValue;
	imageArray[nRow * nWidth * 4 + nCol * 4 + 1] = nValue;
	imageArray[nRow * nWidth * 4 + nCol * 4 + 2] = nValue;
	imageArray[nRow * nWidth * 4 + nCol * 4 + 3] = 255;
}

void saveImage(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height)
{
	//Encode the image
	unsigned error = lodepng::encode(filename, image, width, height);

	//if there's an error, display it
	if (error) std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

bool Map::CheckPlaceIsValid(int nRow,int nCol)
{
	if (nCol * 4 < 0 || nRow < 0 || nCol * 4 > nWidth * 4 - 8 || nRow > nHeight - 4)
		return false;

	return(true);
}


void Map::NewBlow(int yPos, int xPos, int nCount)
{
	int LeftCornerX = xPos - nCount;
	int LeftCornery = yPos - nCount;
	int RightCornerX = xPos + nCount;
	int RightCornery = yPos + nCount;

	for (int nRow = LeftCornery; nRow < RightCornery; nRow++)
	{
		for (int nCol = LeftCornerX; nCol < RightCornerX; nCol++)
		{
			if (CheckPlaceIsValid(nRow, nCol) && GetPositionAsMatrix(nRow, nCol) == BLANK)
			{
				SetPositionAsMatrix(nRow, nCol, NEW_FULL);
			}

		}
	}

}

bool Map::CheckCell(int nRow, int nCol, int nCellsToCheck)
{
	int nNumOfBlack = 0;
	int nNumOfNewBlacks = 0;
	nRow *= nCellsToCheck;
	nCol *= nCellsToCheck;
	int Result;

	for (int nRowOfset = 0; nRowOfset < nCellsToCheck; nRowOfset += 1)
	{
		for (int nColOfset = 0; nColOfset < nCellsToCheck; nColOfset += 1)
		{
			if (CheckPlaceIsValid(nRow + nRowOfset, nCol + nColOfset))
			{
				Result = GetPositionAsMatrix(nRow + nRowOfset, nCol + nColOfset);

				if (Result == FULL)
				{
					nNumOfBlack++;
				}
				else if (Result == NEW_FULL)
				{
					nNumOfNewBlacks++;
				}
			}

		}
	}

	if ((nNumOfBlack > 0) || (nNumOfNewBlacks > 2))
		return true;
	else
		return false;

}

void Map::MakeGridFromImage(const char* filename, bool **GridMap, int *nGridWidth, int *nGridHight)
{
	ConfigurationMGR *pntConfiguration;
	int CellsToBlow;

	pntConfiguration = pntConfiguration->getInstance();

	lodeImage(filename);

	CellsToBlow = (pntConfiguration->RobotSize / 2) / (pntConfiguration->MapResolutionCM);

	// Running over all the png map and blow it in CellsToBlow value
	for (unsigned int nRow = 0; nRow < nHeight; nRow += 1)
	{
		for (unsigned int nCol = 0; nCol < nWidth; nCol += 1)
		{
			if (GetPositionAsMatrix(nRow, nCol) == FULL)
			{
				NewBlow(nRow, nCol, CellsToBlow);
			}
		}
	}

	int PixelInGrid;
	const char* newfile = "hospital_section2.png";

	saveImage(newfile, imageArray, nWidth, nHeight);
	int nMapHight, nMapWidth;


	PixelInGrid = pntConfiguration->GridResolutionCM / pntConfiguration->MapResolutionCM;

	ofstream myFile;
	system("rm map.txt");
	myFile.open("map.txt");

	nMapHight = nHeight / PixelInGrid;
	nMapWidth = nWidth / PixelInGrid;

	int dividePNGToGrid = pntConfiguration->GridResolutionCM/pntConfiguration->MapResolutionCM;

	pntConfiguration->StartLocation.Xpos /=dividePNGToGrid;
	pntConfiguration->StartLocation.Ypos /=dividePNGToGrid;
	pntConfiguration->Goal.Xpos /=dividePNGToGrid;
	pntConfiguration->Goal.Ypos /=dividePNGToGrid;

	cout << pntConfiguration->Goal.Xpos << "    " << pntConfiguration->Goal.Ypos << endl;
	cout << pntConfiguration->StartLocation.Xpos << "    " << pntConfiguration->StartLocation.Ypos << endl;


	GridMap = new bool*[nMapHight];
	for (int i = 0; i < nMapHight; ++i)
		GridMap[i] = new bool[nMapWidth];


		for (int nRow = 0; nRow < nMapHight; nRow +=1)
		{
			for (int nCol = 0; nCol < nMapWidth; nCol += 1)
			{
				GridMap[nRow][nCol] = CheckCell(nRow,nCol,PixelInGrid);
				if((nRow == pntConfiguration->StartLocation.Ypos && nCol == pntConfiguration->StartLocation.Xpos) ||
						(nRow == pntConfiguration->Goal.Ypos && nCol == pntConfiguration->Goal.Xpos))
				{
					myFile << '2';
				}
				else
				{
					myFile << GridMap[nRow][nCol];
				}
			}

			myFile << '\n';
	}
myFile.close();
		*nGridWidth = nMapWidth;
		*nGridHight = nMapHight;

}
