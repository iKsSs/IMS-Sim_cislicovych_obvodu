#include "NOT.h"

bit NOT::getY()
{		
	if (this->A == H)
		return L;
	else if (this->A == L)
		return H;
}