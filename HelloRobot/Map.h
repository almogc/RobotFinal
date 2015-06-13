/*
 * Map.h
 */

class Map {
public:
	void MakeGridFromImage(const char* filename);



private:
	bool CheckCell(int nRow, int nCol, int nCellsToCheck);
	bool CheckPlaceIsValid(int nRow,int nCol);
	void NewBlow(int yPos, int xPos, int nCount);
};
