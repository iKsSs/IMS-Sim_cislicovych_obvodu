#include "NOR.h"

NOR::NOR()
{

}

bit NOR::getY()
{
	if (this->A == X || this->B == X)
		return X;
	else if (this->A == H || this->B == H)
		return L;
	else
		return H;

	return X;
}