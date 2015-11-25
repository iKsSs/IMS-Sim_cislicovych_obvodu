#ifndef IMS__CLKGen
#define IMS__CLKGen

#include "Connect.h"
#include "Scheduler.h"

class CLKgen
{
private:
	Scheduler *scheduler;
public: 
	CLKgen() {}
	CLKgen(unsigned int, unsigned int, Connect *);
};

#endif