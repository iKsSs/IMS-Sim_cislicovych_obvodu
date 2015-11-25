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
		if (this->q[i]->time == e->time)		//ji� existuje vektor s dan�m �asem, tak do n�j jen vlo�� z�znam
		{
			this->q[i]->events.push_back(e);

			return;
		}
	}

	//nen� to tu, je pot�eba vytvo�it nov� z�znam

	SchedulerEvents *tmp = new SchedulerEvents;
	tmp->time = e->time;
	tmp->events.push_back(e);

	this->q.push_back(tmp);

	//pokud fronta pr�zdn� nen�, projde j�, najde zda existuje z�znam z dan�m �asem, do n�j zap�e pokud existuje, pokud neexistuje, dan� z�znam vytvo��
}

SchedulerEvents* Scheduler::getNextEvents()		//rozhoduje po�ad� vkl�d�n� do pl�nova�e (d��ve m� p�ednost) a �as (d��v�j�� prov�d�n� m� p�ednost)
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
