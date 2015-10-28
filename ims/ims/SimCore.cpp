#include "SimCore.h"
#include "Scheduler.h"

#include <iostream>

SimCore::SimCore(SIM_TYPE, int time, int resolution)
{
	if (time < 0 || resolution < 0) throw("Chyba parametr� simulace.\n");
	if (time <= resolution) throw("Chyba parametr� simulace.\n");

	this->resolution = resolution;
	this->time = time;

	this->elapsedTime = 0;

	this->logicTable = LogicsTable::instance();
	this->connections = Connections::instance();
}

void SimCore::init()
{
	//prvnotni nastaveni sb�rnic????
}

void SimCore::printResult()
{
	//vypis hodnot se sb�rnice
	int count = this->connections->cons.size();
	int i;

	for (i = 0; i < count; ++i)
	{
		//pro vypis, vypisuju stavy sb�rnice
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
		//proveden� operace z pl�nu

		SchedulerEvent* e = scheduler->getNextEvent();

		if (elapsedTime != e->time)			//vypisuje v�dy a� po prov�d�n� v�ech akc� ve stejn�m simula�n�m �ase
		{
			this->printResult();
		}

		elapsedTime = e->time;

		bit b = e->b;
		Connect *c = (Connect*)e->c;

		c->setValue(b);

		//prob�hlo nastaven� z kalend��e

		//prob�hne v�po�et a pl�nov�n� nov�ch hodnot na z�klad� t�chto zm�n

		int count = this->connections->cons.size();

		for (int i = 0; i < count; ++i)
		{
			vector<bits*> outs;
			outs = this->connections->cons[i]->getNextValues();
			//ted zname �asy a stavy, ktere mame na teto sb�rnici nastavit

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