#pragma once
ref class Cell
{
private:

	int row;
	int col;
	bool access;
	bool hasBeeper;

	Cell(void);

public:

	Cell(int r, int c, bool a);

	bool getAccess() {return access;}
	int getRow() {return row;}
	int getCol() {return col;}
	bool getBeeper() {return hasBeeper;}

	void setAccess(bool a) {access = a;}
	void setBeeper(bool beeper) {hasBeeper = beeper;}
};

