#pragma once
#include <bitset>
#include <vector>
#include <iostream>
#include "defines.h"

class coord
{

public:
	coord(std::vector<float> P); // P is an int array of the coordinates of the point
	std::vector<float> Point;
	coord();

};

