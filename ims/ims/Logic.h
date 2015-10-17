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
	unsigned char delta;
	string name;

public:
	virtual bit getY() = 0;
	
	void setA(bit);
	void setB(bit);
	void setName(string);

	void setDelta(unsigned char);
	unsigned char getDelta();
};

#endif
