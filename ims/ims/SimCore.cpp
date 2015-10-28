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

void SimCore::run()									//a nebo parametry simulace tady místo do konstruktoru???
{
	Scheduler *scheduler = Scheduler::instance();

	while (this->elapsedTime <= this->time)			///time, resolution je ve stejnych jednotkách
	{
		//pokud je zmìna stavu sbìrnice, navolá hradla na ní navolané, nastaví èasy do timemanageru a 
		//po uplynutí èasù nastaví sbìrnice do odpovídajících hodnot, a pak se celý dìj zase opakuje

		//predpokladejme, že jsme v èase t, kdy se má provést jistý úkol simulace, tedy probìhne spuštìní a analýza celého modelu

		int count = this->connections->cons.size();
		int i;

		for (i = 0; i < count; ++i)
		{
			//pro vypis, vypisuju stavy sbìrnice
			cout << "Time: " << elapsedTime << ": ";
			cout << "Bus " << this->connections->cons[i]->getName() << ": ";
			cout << "Value: " << this->connections->cons[i]->getValue() << endl;
		}

		for (i = 0; i < count; ++i)
		{
			vector<bits*> outs;
			outs = this->connections->cons[i]->getNextValues();
			//ted zname èasy a stavy, ktere mame na teto sbìrnici nastavit

			int count2 = outs.size();
			int j;

			for (j = 0; j < count2; ++j)
			{
				//cout << "In time: " << elapsedTime + outs[j]->time << " set Bus ";
				//cout <<  ((Connect*)outs[j]->c)->getName() << ": ";
				//cout << "Value: " << outs[j]->b << endl;

				SchedulerEvent *e = (SchedulerEvent*)outs[j];
				e->time += elapsedTime;
				scheduler->addEvent(e);			//naplanoval udalost
			}
		}

		cout << endl;

		if (scheduler->isEmpty())
		{
			break;			//nic neni, co by se zmenilo, simulace muze skonèit
		}
		
		SchedulerEvent* e = scheduler->getNextEvent();

		//provedeni akci
		bit b = e->b;
		Connect *c = (Connect*)e->c;

		c->setValue(b);

		this->elapsedTime = e->time; //novy simulaèní èas
	}
}