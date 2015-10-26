#include "SimCore.h"

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
	//do event manageru naplanuje init???

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

		cout << endl;

		for (i = 0; i < count; ++i)
		{
			bit b = this->connections->cons[i]->getValue();
			//ted probìhl dotaz na všechny hradla, ty aktualizovaly pøípadnì stav sbìrnice a nyní je potøeba sbìrnici nastavit do nového stavu
			this->connections->cons[i]->setValue(b);
		}

		//prochazi jednotlivé propojení a zjistí jejich stav (X, L, H) a nastaví nový stav pøípadnì, to vše za použití metod set/getValue
		
		elapsedTime += resolution;   //zde bude posun case dle planovani dalsi nadchazejici udalosti, udalosti bude 
		//vlastne nastaveni sbernice na nejakou konkretní hodnotu, time manager teda bude pøíjmat kdy to má provést, 
		//co má vložit na sbìrnici a na kterou sbìrnici to má udìlat
	}
}