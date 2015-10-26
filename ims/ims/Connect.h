#include <vector>
#include <string>

#include "Logic.h"

using namespace std;

#ifndef __CONNECT_
#define __CONNECT_

class Connect
{
private:
	bit state;
	vector<string> pins;  //jmena hradel s teckovou notaci portu, dane hradlo se poté nalezne v tabulce hradel (vektor)
	string name;
public:
	Connect();
	void setValue(bit);
	bit getValue();  //return state
	void setName(string);
	string getName();
	void addToNode(string);
};

#endif
