/**
* @file RobotInterface.h
* @Author Omer Berkan Calik,Berk Bulgan
* @date January, 2018
* @brief This file is for RobotInterface class definition.
*/

#pragma once
#include "Position.h"
#include "RangeSensor.h"
#include "PioneerRobotAPI.h"
using namespace std;

//! RobotInterface Class.
class RobotInterface
{
protected:
	Position* position;
	vector <RangeSensor*>rangeSensor;
public:
	//! An ENUM.
	/*!
	  This enum is for directions.
	*/
	enum DIRECTION {
		  left = -1 /*! Left Direction.*/
		, forward = 0 /*! Current Direction.*/
		, right = 1 /*! Right Direction.*/
	};
	//! Constructor.
	RobotInterface();
	//! This changes the position with the given Position object.
	void setPosition(Position*);
	//! This pushes the given sensors to the RangeSensor vector.
	void setSensor(RangeSensor*, RangeSensor*);
	//! Pure virtual function for updating the robot. PioneerRobotInterface uses this.
	virtual void update() = 0;
	//! Pure virtual function for connecting to the robot. PioneerRobotInterface uses this.
	virtual bool open() = 0;
	//! Pure virtual function for disconnecting from the robot. PioneerRobotInterface uses this.
	virtual bool close() = 0;
	//! Pure virtual function for moving the robot. PioneerRobotInterface uses this.
	virtual void move(float speed) = 0;
	//! Pure virtual function for turning the robot to the given direction. PioneerRobotInterface uses this.
	virtual void turn(DIRECTION dir) = 0;
	//! Pure virtual function for stopping the robot. PioneerRobotInterface uses this.
	virtual void stop() = 0;
	//! Destructor.
	virtual ~RobotInterface();


};

