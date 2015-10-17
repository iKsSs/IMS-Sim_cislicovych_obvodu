#include <vector>
#include "Logic.h"

using namespace std;

class Connect
{
private:
	bit state;
	vector<string> pins;  //jmena hradel s teckovou notaci portu, dane hradlo se poté nalezne v tabulce hradel (vektor)
public:
	void setValue(bit);
	bit getValue();  //return state
};