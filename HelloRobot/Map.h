/*
 * Map.h
 */

#ifndef MAP_H_
#define MAP_H_

class Map {
public:
	void MakeGridFromImage(int **&GridMap, int *nGridWidth, int *nGridHight);

private:
	int CheckCell(int nRow, int nCol, int nCellsToCheck);
	bool CheckPlaceIsValid(int nRow,int nCol);
	void NewBlow(int yPos, int xPos, int nCount);
	void lodeImage(const char* filename);
	int GetPositionAsMatrix(int nRow, int nCol);
	void SetPositionAsMatrix(int nRow, int nCol, int nValue);
};

#endif
