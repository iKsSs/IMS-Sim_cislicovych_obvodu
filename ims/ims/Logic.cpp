#include "Logic.h"

void Logic::setA(bool A)
{
	this->A = A;
}

void Logic::setB(bool B)
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

string Logic::toString()
{
	if (this->A && this->B)
		return "A1 B1";
	else if (this->A)
		return "A1 B0";
	else if (this->B)
		return "A0 B1";
	else
		return "A0 B0";
}