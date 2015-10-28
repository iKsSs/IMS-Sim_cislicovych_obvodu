#include "NOT.h"

NOT::NOT()
{

}

bit NOT::getY()
{		
	if (this->A == H)
		return L;
	else if (this->A == L)
		return H;
	
	return X;
}