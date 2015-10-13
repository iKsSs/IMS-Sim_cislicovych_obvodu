#include "Logic.h"

void Logic::setA(bit A)
{
	this->A = A;
}

void Logic::setB(bit B)
{
	this->B = B;
}

void Logic::setDelta(unsigned char delta)
{
	this->delta = delta;
}

unsigned char Logic::getDelta()
{
	return this->delta;
}
