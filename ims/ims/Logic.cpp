#include "Logic.h"

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

void Logic::setLastChange(int time)				//nutno ze simulátoru volat po každé zmìnì vstupù hradla!!! Øešeno takto, a nejsou globalni promenné
{
	this->lastChange = time;
}
