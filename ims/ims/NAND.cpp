#include "NAND.h"

NAND::NAND()
{

}

bit NAND::getY()
{

	if (this->A == L || this->B == L)
		return H;
	else if (this->A == H && this->B == H)
		return L;

	return X;
}
