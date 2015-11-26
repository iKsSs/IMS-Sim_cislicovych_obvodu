#include "AND.h"

bit AND::getY()
{
	if (this->A == L || this->B == L)
		return L;
	else if (this->A == H && this->B == H)
		return H;

	return X;
}
