#include "CLKGen.h"

CLKgen::CLKgen(unsigned int period, unsigned int max_time, Connect *clk)
{
	if (period % 2 != 0)
	{
		throw "Period has to be divisible by 2";
	}
	
	this->scheduler = Scheduler::instance();

	for (unsigned int i = 0; i <= max_time; i += period)
	{
		SchedulerEvent *eL = new SchedulerEvent;
		SchedulerEvent *eH = new SchedulerEvent;
		
		eL->b = L;
		eL->c = clk;
		eL->time = i;
		eL->l = NULL;

		this->scheduler->addEvent(eL);

		eH->b = H;
		eH->c = clk;
		eH->time = i + (period / 2);
		eH->l = NULL;

		this->scheduler->addEvent(eH);
	}
}
