/*
 * main.c  pp
 *
 *  Created on: Jan 10, 2015
 *      Author: colman
 */

#include "lodepng.h"
#include "Globals.h"
#include "Map.h"
#include <iostream>
#include <libplayerc++/playerc++.h>
#include <fstream>

using namespace PlayerCc;

using namespace std;

std::vector<unsigned char> image; //the raw pixels
unsigned width, height;

//Example 1
//Decode from disk to raw pixels with a single function call
void lodeImage(const char* filename)
{
  //decode
  unsigned error = lodepng::decode(image, width, height, filename);

  //if there's an error, display it
  if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

  //the pixels are now in the vector "image", 4 bytes per pixel, ordered RGBARGBA..., use it as texture, draw it, ...
}

//Example 1
//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void saveImage(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height)
{
  //Encode the image
  unsigned error = lodepng::encode(filename, image, width, height);

  //if there's an error, display it
  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

int GetPositionAsMatrix (int nCol, int nRow)
{
	return (image[nCol*4 + nRow * width *4]);
}
void SetPositionAsMatrix (int nCol, int nRow,int nValue)
{
	image[nCol*4 + nRow * width *4] = nValue;
	image[nCol*4 + 1 + nRow * width *4] = nValue;
	image[nCol*4 + 2 + nRow * width *4] = nValue;
	image[nCol*4 + 3 + nRow * width *4] = 255;
}


const int BLANK = 255;
const int FULL = 0;


bool CheckPoint(int xPos,int yPos)
{
	if(xPos * 4 < 0|| yPos < 0 || xPos * 4 > width * 4 - 8 || yPos > height - 4)
		return false;

	return(true);
}

void NewBlow(int xPos,int yPos,int nCount)
{
	int LeftCornerX = xPos - nCount;
	int LeftCornery = yPos - nCount;
	int RightCornerX = xPos + nCount;
	int RightCornery = yPos + nCount;

	for(int nCol = LeftCornerX; nCol<RightCornerX; nCol++)
	{
		for(int nRow = LeftCornery; nRow<RightCornery; nRow++)
		{
			if(CheckPoint(nCol,nRow) && GetPositionAsMatrix(nCol, nRow) == BLANK)
			{
				SetPositionAsMatrix(nCol, nRow, 6);
			}

		}
	}

}

void ReadParametersFile()
{
	string FileContent, FileVariable;
	ifstream infile;
	size_t Pos;
	Globals *pntGlobals;
	pntGlobals = pntGlobals->getInstance();

	infile.open ("parameters.txt");
	if (infile.is_open()) {
	while(!infile.eof())
        {
			getline(infile,FileContent);
			Pos = FileContent.find(": ");
			FileVariable = FileContent.substr(0,Pos);
			if (!FileVariable.compare("map"))
			{
				pntGlobals->mapLocation = FileContent.substr(Pos+2,FileContent.length());
				cout << pntGlobals->mapLocation << endl;
			}
			else if (!FileVariable.compare("startLocation"))
			{
				FileContent = FileContent.substr(Pos+2,FileContent.length());

				Pos = FileContent.find(" ");
				pntGlobals->StartLocation.Xpos = atoi(FileContent.substr(0,Pos).c_str());
				FileContent = FileContent.substr(Pos+1,FileContent.length());

				Pos = FileContent.find(" ");
				pntGlobals->StartLocation.Ypos = atoi(FileContent.substr(0,Pos).c_str());
				FileContent = FileContent.substr(Pos+1,FileContent.length());

				pntGlobals->StartLocation.Yaw = atoi(FileContent.substr(0,Pos-1).c_str());
			}
			else if (!FileVariable.compare("goal"))
			{
				FileContent = FileContent.substr(Pos+2,FileContent.length());

				Pos = FileContent.find(" ");
				pntGlobals->Goal.Xpos = atoi(FileContent.substr(0,Pos).c_str());
				FileContent = FileContent.substr(Pos+1,FileContent.length());

				pntGlobals->Goal.Ypos = atoi(FileContent.substr(0,Pos).c_str());
			}
			else if (!FileVariable.compare("robotSize"))
			{
				FileContent = FileContent.substr(Pos+2,FileContent.length());
				Pos = FileContent.find(" ");

				pntGlobals->RobotSize = atof(FileContent.substr(0,Pos).c_str());
			}
			else if (!FileVariable.compare("MapResolutionCM"))
			{
				pntGlobals->MapResolutionCM  = atof(FileContent.substr(Pos+2,FileContent.length()-1).c_str());
			}
			else if (!FileVariable.compare("GridResolutionCM"))
			{
				pntGlobals->GridResolutionCM  = atof(FileContent.substr(Pos+2,FileContent.length()-1).c_str());
			}
        }
	}
	infile.close();

}


int main() {





	ReadParametersFile();
	const char* filename = "Maps/roboticLabMap.png";
		lodeImage(filename);

		cout << "width: " << width << ", height: " << height << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << (int)image[i] << " ";
		}
		cout << endl;




		Map a;
		a.MakeGridFromImage();

		//  Change the first line to black
		for (unsigned int nRow = 0; nRow < height  - 4; nRow+=1)
		{
			for (unsigned int nCol = 0; nCol < width*4 -8; nCol+=1)
				{
					if(GetPositionAsMatrix(nCol,nRow) == FULL)
					{
						NewBlow(nCol,nRow,15);
					}
				}
		}

		const char* newfile = "hospital_section2.png";
	saveImage(newfile, image, width, height);






//	PlayerClient pc("localhost", 6665);
//	LaserProxy lp(&pc);
//	Position2dProxy pp(&pc);

//	pp.SetMotorEnable(true);
//	while (true) {

//		pc.Read();

//		if (lp[333] < 0.8)
//			pp.SetSpeed(0.0, 0.3);
//		else
//			pp.SetSpeed(0.8, 0.0);

//	}

//		if (lp[333] < 0.8)
//			pp.SetSpeed(0.0, 0.3);
//		else
//			pp.SetSpeed(0.8, 0.0);

//	}

	return 0;

}
