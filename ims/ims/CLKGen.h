#include "Connect.h"
#include "Scheduler.h"

class CLKgen
{
private:
	Scheduler *scheduler;
public: 
	CLKgen(unsigned int, unsigned int, Connect *);
};
