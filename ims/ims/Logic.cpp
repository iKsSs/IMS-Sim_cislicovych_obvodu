#include "Logic.h"

Logic::Logic()
{
	this->A = this->B = X;
	this->delta = 0;
	this->Y = X;
	this->name = "";
}

void Logic::setA(bit A)
{ 
	this->A = A;
}

void Logic::setB(bit B)
{
	this->B = B;
}

void Logic::setName(string name)
{
	this->name = name;
}

string Logic::getName()
{
	return this->name;
}

void Logic::setDelta(unsigned char delta)
{
	this->delta = delta;
}

unsigned char Logic::getDelta()
{
	return this->delta;
}

