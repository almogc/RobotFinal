/*
 * Map.h
 */

class Map {
public:
	void MakeGridFromImage(const char* filename, bool **GridMap, int *nGridWidth, int *nGridHight);

private:
	bool CheckCell(int nRow, int nCol, int nCellsToCheck);
	bool CheckPlaceIsValid(int nRow,int nCol);
	void NewBlow(int yPos, int xPos, int nCount);
	void lodeImage(const char* filename);
	int GetPositionAsMatrix(int nRow, int nCol);
	void SetPositionAsMatrix(int nRow, int nCol, int nValue);
};
