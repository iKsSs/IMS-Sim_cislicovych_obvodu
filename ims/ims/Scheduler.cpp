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
	//this->q.push_back(e);
	Logic *l = (Logic*)e->l;

	unsigned int count = this->q.size();
	unsigned int i;

	if (l != NULL)		//event zasila hradlo
	{
		for (i = 0; i < count; ++i)
		{
			if (this->q[i]->time > e->time - l->getDelta())		//casy, kdy mohlo hradlo neco planovat a od ktere doby jeste neuplynulo zpozdeni
			{
				unsigned int count2 = this->q[i]->events.size();
				unsigned int j;

				for (j = 0; j < count2; ++j)
				{
					//planovalo nejaky zaznam toto hradlo?
					Logic *ll = (Logic *)this->q[i]->events[j]->l;

					if (ll == l)
					{
						//zahazuju pozadavek na planovani

						return;
					}
				}
			}
		}
	}

	for (i = 0; i < count; ++i)
	{
		if (this->q[i]->time == e->time)		//již existuje vektor s daným èasem, tak do nìj jen vloží záznam
		{
			this->q[i]->events.push_back(e);

			return;
		}
	}

	//není to tu, je potøeba vytvoøit nový záznam

	SchedulerEvents *tmp = new SchedulerEvents;
	tmp->time = e->time;
	tmp->events.push_back(e);

	this->q.push_back(tmp);

	//pokud fronta prázdná není, projde jí, najde zda existuje záznam z daným èasem, do nìj zapíše pokud existuje, pokud neexistuje, daný záznam vytvoøí
}

SchedulerEvents* Scheduler::getNextEvents()		//rozhoduje poøadí vkládání do plánovaèe (døíve má pøednost) a èas (døívìjší provádìní má pøednost)
{
	SchedulerEvents* tmp = this->q.front();
	this->min_index = 0;
	
	for (unsigned int i = 0; i < this->q.size(); ++i)
	{
		if (this->q[i]->time < tmp->time)
		{
			tmp = this->q[i];
			this->min_index = i;
		}
	}

	this->popEvent();

	return tmp;
}

void Scheduler::popEvent()
{
	this->q.erase(this->q.begin() + min_index);
}

bool Scheduler::isEmpty()
{
	return this->q.empty();
}
