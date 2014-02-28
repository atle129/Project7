#include "Mouse.h"


Mouse::Mouse(void)
{
}

Mouse::Mouse(int newRow, int newCol)
{
	row = 0;
	col = 0;
	icon = 0;

	if (newRow >= 0) row = newRow;
	if (newCol >= 0) col = newCol;
}

System::Drawing::Icon^ Mouse::getIcon()
{
	if (icon == 0)
		return mouseRight;
	else if (icon == 1)
		return mouseLeft;
	else if (icon == 2)
		return mouseUp;
	else
		return mouseDown;
}

void Mouse::turnLeft()
{
	if (icon == 0)
		icon = 2;
	else if (icon == 1)
		icon = 3;
	else if (icon == 2)
		icon = 1;
	else if (icon == 3)
		icon = 0;
}

void Mouse::move()
{
	if (icon == 0)
		goRight();
	else if (icon == 1)
		goLeft();
	else if (icon == 2)
		goUp();
	else
		goDown();
}