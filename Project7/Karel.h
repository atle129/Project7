#pragma once
ref class Karel
{
public:

	Karel(int row, int col);

	int getRow() {return row;}
	int getCol() {return col;}
	int getIco() {return icon;}
	System::Drawing::Icon^ Karel::getIcon();

	void setRow(int newRow) {row = newRow;}
	void setCol(int newCol) {col = newCol;}

	void goRight() {col++;}
	void goLeft() {col--;}
	void goUp() {row--;}
	void goDown() {row++;}

	void turnLeft();
	void move();

private:

	static System::Drawing::Icon^ karelRight = gcnew System::Drawing::Icon("robotRight.ico");
	static System::Drawing::Icon^ karelLeft = gcnew System::Drawing::Icon("robotLeft.ico");
	static System::Drawing::Icon^ karelUp = gcnew System::Drawing::Icon("robotUp.ico");
	static System::Drawing::Icon^ karelDown = gcnew System::Drawing::Icon("robotDown.ico");

	int row;
	int col;
	int icon;

	Karel(void);
};

