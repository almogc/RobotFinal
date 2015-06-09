/*
 * main.cpp
 *
 *  Created on: Jan 10, 2015
 *      Author: colman
 */

#include "lodepng.h"
#include <iostream>
#include <libplayerc++/playerc++.h>

using namespace PlayerCc;

using namespace std;

std::vector<unsigned char> image; //the raw pixels
unsigned width, height;

//Example 1
//Decode from disk to raw pixels with a single function call
void loadImage(const char* filename)
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
				SetPositionAsMatrix(nCol, nRow, 1);
			}

		}
	}

}



int main() {


	const char* filename = "roboticLabMap.png";
		loadImage(filename);

		cout << "width: " << width << ", height: " << height << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << (int)image[i] << " ";
		}
		cout << endl;

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
