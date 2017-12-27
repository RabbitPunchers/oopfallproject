#include "Position.h"



Position::Position()
{
	x = 0;
	y = 0;
	th = 0;
}


Position::~Position()
{
}

float Position::getX()
{
	return x;
}
void Position::setX(float _x)
{
	x = _x;
}
float Position::getY()
{
	return y;
}
void Position::setY(float _y)
{
	y = _y;
}
float Position::getTh()
{
	return th;
}
void Position::setTh(float _th)
{
	th = _th;
}
bool Position::operator==(const Position& pos)
{
	if (x == pos.x && y == pos.y && th == pos.th)
		return true;
	else
		return false;
}