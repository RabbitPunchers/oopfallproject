/**
 * @file Position.h
 * @Author Ömer Berkan Çalýk, Ibrahim Berk Bulgan
 * @date January, 2018
 * @brief This file is for Position class definition.
*/

#pragma once

//! Position Class.
/*!
  This class is for storing and changing the coordinates
  and orientation angle.
*/
class Position
{
	//! This is for storing x-coordinate.
	float x;
	//! This is for storing y-coordinate.
	float y;
	//! This is for storing the orientation angle.
	float th;
public:
	//! Constructor.
	Position();
	//! Destructor.
	~Position();
	//! This returns the x value.
	float getX();
	//! This changes the x with the given value.
	void setX(float);
	//! This returns the y value.
	float getY();
	//! This changes the y with the given value.
	void setY(float);
	//! This returns the th value.
	float getTh();
	//! This changes the th with the given value.
	void setTh(float);
	//! Operator overloading for == operator.
	bool operator==(const Position&);
};

