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

	//system("pause");
	//konec vypisu
}

void SimCore::run()
{
	Scheduler *scheduler = Scheduler::instance();

	while (this->elapsedTime <= this->time)
	{
		SchedulerEvent* e;

		while(!scheduler->isEmpty())			//provede všechny události v daný simulaèní èas
		{
			e = scheduler->getNextEvent();

			bit b = e->b;
			Connect *c = (Connect*)e->c;

			c->setValue(b);

			cout << "Set bus name: " << c->getName() <<  "to value: " << e->b << endl;

			if (e->time > this->elapsedTime)
				break;

			scheduler->popEvent();
		}

		elapsedTime = e->time;		//novy simulaèní èas

		//pøepoèet modelu
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

		cout << "Now: " << endl;
		printResult();

		cout << endl << endl;

		//co naplanoval:

		cout << "Print scheduler:" << endl;
		for (int i = 0; i < scheduler->q.size(); ++i)
		{
			cout << "In time: " << scheduler->q[i]->time;
			cout << " set bus name: " << ((Connect*)(scheduler->q[i]->c))->getName();
			cout << " to value: " << scheduler->q[i]->b << endl;

		}
		cout << endl << endl;
	}
}