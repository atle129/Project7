#pragma once
ref class Cell
{
private:

	int row;
	int col;
	bool access;
	bool hasCheese;

	Cell(void);

public:

	Cell(int r, int c, bool a);

	bool getAccess() {return access;}
	int getRow() {return row;}
	int getCol() {return col;}
	bool getCheese() {return hasCheese;}

	void setAccess(bool a) {access = a;}
	void setCheese(bool cheese) {hasCheese = true;}
};

