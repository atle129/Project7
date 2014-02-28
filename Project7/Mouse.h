#pragma once
ref class Mouse
{
public:

	Mouse(int row, int col);

	int getRow() {return row;}
	int getCol() {return col;}
	System::Drawing::Icon^ Mouse::getIcon();

	void setRow(int newRow) {row = newRow;}
	void setCol(int newCol) {col = newCol;}

	void goRight() {col++;}
	void goLeft() {col--;}
	void goUp() {row--;}
	void goDown() {row++;}

	void turnLeft();
	void move();

private:

	static System::Drawing::Icon^ mouseRight = gcnew System::Drawing::Icon("mouseRight.ico");
	static System::Drawing::Icon^ mouseLeft = gcnew System::Drawing::Icon("mouseLeft.ico");
	static System::Drawing::Icon^ mouseUp = gcnew System::Drawing::Icon("mouseUp.ico");
	static System::Drawing::Icon^ mouseDown = gcnew System::Drawing::Icon("mouseDown.ico");

	int row;
	int col;
	int icon;

	Mouse(void);
};

