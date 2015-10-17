#include <vector>
#include "Logic.h"

using namespace std;

#ifndef __CONNECT_
#define __CONNECT_

class Connect
{
private:
	bit state;
	vector<string> pins;  //jmena hradel s teckovou notaci portu, dane hradlo se poté nalezne v tabulce hradel (vektor)
public:
	void setValue(bit);
	bit getValue();  //return state
};

#endif
