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

void SimCore::run()									//a nebo parametry simulace tady m�sto do konstruktoru???
{
	Scheduler *scheduler = Scheduler::instance();

	while (this->elapsedTime <= this->time)			///time, resolution je ve stejnych jednotk�ch
	{
		//pokud je zm�na stavu sb�rnice, navol� hradla na n� navolan�, nastav� �asy do timemanageru a 
		//po uplynut� �as� nastav� sb�rnice do odpov�daj�c�ch hodnot, a pak se cel� d�j zase opakuje

		//predpokladejme, �e jsme v �ase t, kdy se m� prov�st jist� �kol simulace, tedy prob�hne spu�t�n� a anal�za cel�ho modelu

		int count = this->connections->cons.size();
		int i;

		for (i = 0; i < count; ++i)
		{
			//pro vypis, vypisuju stavy sb�rnice
			cout << "Time: " << elapsedTime << ": ";
			cout << "Bus " << this->connections->cons[i]->getName() << ": ";
			cout << "Value: " << this->connections->cons[i]->getValue() << endl;
		}

		for (i = 0; i < count; ++i)
		{
			vector<bits*> outs;
			outs = this->connections->cons[i]->getNextValues();
			//ted zname �asy a stavy, ktere mame na teto sb�rnici nastavit

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
			break;			//nic neni, co by se zmenilo, simulace muze skon�it
		}
		
		SchedulerEvent* e = scheduler->getNextEvent();

		//provedeni akci
		bit b = e->b;
		Connect *c = (Connect*)e->c;

		c->setValue(b);

		this->elapsedTime = e->time; //novy simula�n� �as
	}
}