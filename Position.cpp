/**
* @file Position.cpp
* @Author Omer Berkan Calik, Ibrahim Berk Bulgan
* @date January, 2018
* @brief This file is for Position class' function's definitions.
*/
#include "Position.h"
Position::Position()
{
	x = 0;
	y = 0;
	th = 0;
}


Position::~Position(){}

/*!
	\return Returns robots X coordinate.
*/
float Position::getX()
{
	return x;
}
/*!
	\param _x is an float value for updating robot's X coordinate.
*/
void Position::setX(float _x)
{
	x = _x;
}
/*!
	\return Returns robots Y coordinate.
*/
float Position::getY()
{
	return y;
}
/*!
	\param _y is an float value for updating robot's Y coordinate.
*/
void Position::setY(float _y)
{
	y = _y;
}
/*!
	\return Returns robots facing direction in degrees.
*/
float Position::getTh()
{
	return th;
}
/*!
	\param _th is an float value for updating robot's facing direction.
*/
void Position::setTh(float _th)
{
	th = _th;
}
/*!
	\param pos is a position object to check the equality.
*/
bool Position::operator==(const Position& pos)
{
	if (x == pos.x && y == pos.y && th == pos.th)
		return true;
	else
		return false;
}