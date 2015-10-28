#include "SimCore.h"
#include "Scheduler.h"

#include <iostream>

SimCore::SimCore(SIM_TYPE, int time, int resolution)
{
	if (time < 0 || resolution < 0) throw("Chyba parametrù simulace.\n");
	if (time <= resolution) throw("Chyba parametrù simulace.\n");

	this->resolution = resolution;
	this->time = time;

	this->elapsedTime = 0;

	this->logicTable = LogicsTable::instance();
	this->connections = Connections::instance();
}

void SimCore::init()
{
	//prvnotni nastaveni sbìrnic????
}

void SimCore::printResult()
{
	//vypis hodnot se sbìrnice
	int count = this->connections->cons.size();
	int i;

	for (i = 0; i < count; ++i)
	{
		//pro vypis, vypisuju stavy sbìrnice
		cout << "Time: " << elapsedTime << ": ";
		cout << "Bus " << this->connections->cons[i]->getName() << ": ";
		cout << "Value: " << this->connections->cons[i]->getValue() << endl;
	}

	cout << endl;

	system("pause");
	//konec vypisu
}

void SimCore::run()
{
	this->init();

	Scheduler *scheduler = Scheduler::instance();

	while (this->elapsedTime <= this->time && !scheduler->isEmpty())
	{
		//provedení operace z plánu

		SchedulerEvent* e = scheduler->getNextEvent();

		if (elapsedTime != e->time)			//vypisuje vždy až po provádìní všech akcí ve stejném simulaèním èase
		{
			this->printResult();
		}

		elapsedTime = e->time;

		bit b = e->b;
		Connect *c = (Connect*)e->c;

		c->setValue(b);

		//probìhlo nastavení z kalendáøe

		//probìhne výpoèet a plánování nových hodnot na základì tìchto zmìn

		int count = this->connections->cons.size();

		for (int i = 0; i < count; ++i)
		{
			vector<bits*> outs;
			outs = this->connections->cons[i]->getNextValues();
			//ted zname èasy a stavy, ktere mame na teto sbìrnici nastavit

			int count2 = outs.size();
			int j;

			for (j = 0; j < count2; ++j)
			{
				SchedulerEvent *e = (SchedulerEvent*)outs[j];
				e->time += elapsedTime;
				scheduler->addEvent(e);			//naplanoval udalost
			}
		}
	}
}