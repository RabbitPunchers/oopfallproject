#pragma once
class Position
{
	float x;
	float y;
	float th;
public:
	Position();
	~Position();
	float getX();
	void setX(float);
	float getY();
	void setY(float);
	float getTh();
	void setTh(float);
	bool operator==(const Position&);
};

