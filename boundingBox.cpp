#include "boundingBox.h"

boundingBox::boundingBox(DimensionBitSet D)
{
	dimensions = D;
	int c = 0; // is a counter 
	for (int i = 0; i < TOTALDIMENSIONS; i++)
	{
		c += D[i]; // this will add the bit to the counter as if it is 1 you want to increment it, if 0 you don't so you can just add them
	}
	dimensionsCount = c; // this is show we know how many dimensions this box is in
}

void boundingBox::setSize(std::vector<float>S)
{
	sizes = S;
}

std::vector<float> boundingBox::getSize()
{
	return sizes;
}

void boundingBox::resetPos()
{
	pos.Point.resize(dimensionsCount);
	for (int i = 0; i < dimensionsCount; i++)
	{
		pos.Point[i] = 0;
	}
}

void boundingBox::setPos( coord newpos)
{
	pos = newpos;
	
}

coord boundingBox::getPos()
{
	return pos;
}

void boundingBox::displayBox()
{
	for (int i = 0; i < dimensionsCount; i++)
	{
		std::cout << "dimension " << i << ": min " << pos.Point[i] - (sizes[i] / 2) << ": max " << pos.Point[i] + (sizes[i] / 2) << std::endl;
	}
}

DimensionBitSet boundingBox::getDim()
{
	return dimensions;
}

bool boundingBox::checkCollision(boundingBox other)
{
	DimensionBitSet sharedDims;
	sharedDims.reset();
	sharedDims = dimensions & other.getDim();
	if (sharedDims.none()) { return false; } // if there are no shared dimensions then no collision can occur
	
	// if a true bit was found so these needs to increment so the right index will be used for the dimensional axis 
	int dimCheck1 = 0; 
	int dimCheck2 = 0;

	for (int i = 0; i < TOTALDIMENSIONS; i++) // this can be optimsed but checking all to start to make sure it works
	{
		if (dimensions[i] == 1) // if the bit is one then this is a dimension the object exists in
		{
			if (other.getDim()[i] == 1) // if the bit is one then this is a dimension the other object exists in
			{
				if (!((pos.Point[dimCheck1] - (sizes[dimCheck1] / 2))<(other.getPos().Point[dimCheck2]+(other.getSize()[dimCheck2]/2))&&
					(pos.Point[dimCheck1] + (sizes[dimCheck1] / 2)) > (other.getPos().Point[dimCheck2] - (other.getSize()[dimCheck2] / 2))))
				{
					return false;
				}
				dimCheck2 += 1; 
				
			}
			dimCheck1 += 1;
		}
		else 
		{
			if (other.getDim()[i] == 1)
			{
				dimCheck2 += 1;
			}
			
		}
	}

	return true; // if this point is reached then the boxes have at least 1 shared dimension and none of the checks were false so it must be true
}


