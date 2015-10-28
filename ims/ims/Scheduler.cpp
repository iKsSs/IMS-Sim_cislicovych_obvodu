#include "Scheduler.h"

Scheduler* Scheduler::instance()
{
	if (!pInstance)
	{
		pInstance = new Scheduler;
	}

	return pInstance;
}

void Scheduler::addEvent(SchedulerEvent *e)
{
	this->q.push_back(e);
}

SchedulerEvent* Scheduler::getNextEvent()		//rozhoduje poøadí vkládání do plánovaèe (døíve má pøednost) a èas (døívìjší provádìní má pøednost)
{
	SchedulerEvent* tmp = this->q.front();
	unsigned int min_index = 0;
	
	for (int i = 0; i < this->q.size(); ++i)
	{
		if (this->q[i]->time < tmp->time)
		{
			tmp = this->q[i];
			min_index = i;
		}
	}

	this->q.erase(this->q.begin() + min_index);
	return tmp;
}

bool Scheduler::isEmpty()
{
	return this->q.empty();
}
