#include <string>

using namespace std;

#ifndef __LOGIC__
#define __LOGIC__

class Logic
{
protected:
	bool Y, A, B;
	unsigned char delta;

public:
	virtual bool getY() = 0;
	
	void setA(bool);
	void setB(bool);

	void setDelta(unsigned char);
	unsigned char getDelta();

	string toString();
};

#endif
