#include "Karel.h"


Karel::Karel(void)
{
}

Karel::Karel(int newRow, int newCol)
{
	row = 0;
	col = 0;
	icon = 0;

	if (newRow >= 0) row = newRow;
	if (newCol >= 0) col = newCol;
}

System::Drawing::Icon^ Karel::getIcon()
{
	if (icon == 0)
		return karelRight;
	else if (icon == 1)
		return karelLeft;
	else if (icon == 2)
		return karelUp;
	else
		return karelDown;
}

void Karel::turnLeft()
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

void Karel::move()
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