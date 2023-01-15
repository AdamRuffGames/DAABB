#include "boundingBox.h"

// just used to neaten up the code
void print(bool s)
{
	if (s) {
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "False" << std::endl;
	}
}

int main()
{
	// these are the bits used to determine what dimensions the bounding boxes exist in
	DimensionBitSet box1Dims;
	DimensionBitSet box2Dims;

	// box 1's bits is set to exist in the 0, 1, 2 dimensions
	box1Dims[0] = 1;
	box1Dims[1] = 1;
	box1Dims[2] = 1;
	
	// box 2's bits is set to exist in the 0, 1, 3, 4 dimensions
	box2Dims[0] = 1;
	box2Dims[1] = 1;
	box2Dims[3] = 1;
	box2Dims[4] = 1;
	// the only 2 shared dimensions are 0 and 1
	
	// these are the two bounding boxes they take in the bits to set the dimensions the box alligns to
	boundingBox box1(box1Dims);
	boundingBox box2(box2Dims);

	// this sets the position to the origin (0 in each dimension)
	box1.resetPos();
	box2.resetPos();

	// this is how the size is set if you wanted a 1x2x3 box then you would use setSize({1,2,3})
	box1.setSize({1,1,1});
	box2.setSize({2,2,2,2 });

	print(box1.checkCollision(box2));

	box1.setPos(coord({1.5,0,0})); // this moves box 1 to the position (1.5,0,0)

	print(box1.checkCollision(box2));
}