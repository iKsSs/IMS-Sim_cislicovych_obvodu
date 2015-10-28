#include <vector>
#include <string>

#include "Logic.h"

using namespace std;

#ifndef __CONNECT_
#define __CONNECT_

typedef struct
{
	unsigned int time;
	bit b;
} bits;

typedef struct
{
	Logic *l;
	char pin;
} NodeItem;

class Connect
{
private:
	bit state;
	vector<string> pins;  //jmena hradel s teckovou notaci portu, dane hradlo se poté nalezne v tabulce hradel (vektor)
	vector<NodeItem> nodePins;
	string name;
public:
	Connect();
	void setValue(bit);
	bit getValue();  //return state
	vector<bits> getNextValues(); //vrací hodnoty sbìrnice v následujícíh èasech, jak se vyvolají události na hradlech, po uplynutí zpoždìní
	void setName(string);
	string getName();
	void addToNode(string);
	void addToNode(Logic*, char);
};

#endif
