#include "OR.h"

OR::OR()
{
	this->A = L;
	this->B = L;
}

bit OR::getY()
{
	if (this->A == X || this->B == X)
		return X;
	else if (this->A == H || this->B == H)
		return H;
	else
		return L;

	return X;
}