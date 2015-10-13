#include "AND.h"

bit AND::getY()
{
	if (this->A == X || this->B == X)
		return X;
	else if (this->A == H && this->B == H)
		return H;
	else
		return L;
}
