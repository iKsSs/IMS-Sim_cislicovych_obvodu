#include "SimCore.h"
#include "Scheduler.h"
#include "PlotCreator.h"

#include <iostream>

SimCore::SimCore(SIM_TYPE, int time)
{
	if (time < 0) throw("Chyba parametrù simulace.\n");

	this->time = time;
	this->elapsedTime = 0;

	this->logicTable = LogicsTable::instance();
	this->connections = Connections::instance();
}

void SimCore::printResult()
{
	//vypis hodnot se sbìrnice
	unsigned int count = this->connections->cons.size();
	unsigned int i;

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
	PlotCreator plot("test", this->time);

	while (true)
	{
		if (scheduler->isEmpty())
		{
			break;
		}
		
		SchedulerEvents* e = scheduler->getNextEvents();

		if (e->time > this->time)
		{
			break;
		}

		for (unsigned int i = 0; i < e->events.size(); ++i)
		{
			this->elapsedTime = e->time;		//novy simulaèní èas

			bit b = e->events[i]->b;
			Connect *c = (Connect*)e->events[i]->c;

			c->setValue(b);

			cout << "Set bus name: " << c->getName() << "to value: " << e->events[i]->b << endl;
		}

		cout << endl;

		//pøepoèet modelu
		unsigned int count = this->connections->cons.size();

		for (unsigned int i = 0; i < count; ++i)
		{
			vector<bits*> outs;
			outs = this->connections->cons[i]->getNextValues();
			//ted zname èasy a stavy, ktere mame na teto sbìrnici nastavit

			unsigned int count2 = outs.size();
			unsigned int j;

			for (j = 0; j < count2; ++j)
			{
				SchedulerEvent *e = (SchedulerEvent*)outs[j];

				e->time += elapsedTime;
				scheduler->addEvent(e);			//naplanoval udalost
			}
		}

		cout << "Now: " << endl;
		printResult();
		plot.writeState(elapsedTime);

		cout << endl << endl;

		//co naplanoval:
	}

	plot.closeFile();
}