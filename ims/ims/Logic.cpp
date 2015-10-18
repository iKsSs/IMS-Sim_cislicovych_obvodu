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

void Logic::setLastChange(int time)				//nutno ze simul�toru volat po ka�d� zm�n� vstup� hradla!!! �e�eno takto, a� nejsou globalni promenn�
{
	this->lastChange = time;
}
