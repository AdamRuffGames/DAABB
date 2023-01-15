#pragma once
#include "coord.h"


class boundingBox
{
private:
	DimensionBitSet dimensions;// uses the bits to represent what dimensions this coord is a part of
	coord pos;
	std::vector<float> sizes;

public:
	int dimensionsCount;
	boundingBox(DimensionBitSet D); // D is for which dimensions
	void setSize(std::vector<float> S); // sets the size of the bounding box (size is determined from the center of the object so a 2D box at (0,0) with a size of (1,1) would go from (-0.5,-0.5) to (0.5,0.5)
	std::vector<float> getSize();// gets the size of the bounding box
	void resetPos(); // this sets the position to the origin (0 in each dimension)
	void setPos(coord newpos); // this sets the position to position given
	coord getPos(); // this gets the position 
	void displayBox(); // currently used for debug purposes
	DimensionBitSet getDim(); // this returns the bits that represents the dimensions 

	bool checkCollision(boundingBox other);
};

