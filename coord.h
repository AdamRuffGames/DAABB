#pragma once
#include <bitset>
#include <vector>
#include <iostream>
#include "defines.h"

class coord
{

public:
	coord(std::vector<float> P); // P is a vector of floats representing the point
	std::vector<float> Point;
	coord();

};

