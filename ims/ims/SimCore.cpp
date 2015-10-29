#include "SimCore.h"
#include "Scheduler.h"
#include "PlotCreator.h"

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

	//system("pause");
	//konec vypisu
}

void SimCore::run()
{
	Scheduler *scheduler = Scheduler::instance();
	PlotCreator plot("test", this->time);

	while (this->elapsedTime <= this->time)
	{
		SchedulerEvents* e = scheduler->getNextEvents();

		for (int i = 0; i < e->events.size(); ++i)
		{
			elapsedTime = e->time;		//novy simula�n� �as

			bit b = e->events[i]->b;
			Connect *c = (Connect*)e->events[i]->c;

			c->setValue(b);

			cout << "Set bus name: " << c->getName() << "to value: " << e->events[i]->b << endl;
		}

		cout << endl;

		//p�epo�et modelu
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

		cout << "Now: " << endl;
		printResult();
		plot.writeState(elapsedTime);

		cout << endl << endl;

		//co naplanoval:
	}

	plot.closeFile();
}