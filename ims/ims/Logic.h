#include <string>

using namespace std;

#ifndef __LOGIC__
#define __LOGIC__

typedef enum 
{
	L, 
	H,
	X
}bit;

class Logic
{
protected:
	bit Y, A, B;
	bit state;
	unsigned char delta;
	string name;
	int lastChange;

public:
	virtual bit getY() = 0;
	
	void setA(bit);
	void setB(bit);
	void setName(string);
	void setLastChange(int);			//pak by tohle bylo zbyte�n�, m�m ukazatel na simula�n� �as, t�m p�dem mohu br�t jeho hodnotu
	void setRefSimTime(int *);

	void setDelta(unsigned char);
	unsigned char getDelta();
	string getName();
};

#endif
