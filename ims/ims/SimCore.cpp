#include "SimCore.h"

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
	//do event manageru naplanuje init???

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
			vector<bits> outs;
			outs = this->connections->cons[i]->getNextValues();
			//ted zname �asy a stavy, ktere mame na teto sb�rnici nastavit

			int count2 = outs.size();
			int j;

			for (j = 0; j < count2; ++j)
			{
				cout << "In time: " << elapsedTime + outs[j].time << " set Bus ";
				cout <<  this->connections->cons[i]->getName() << ": ";
				cout << "Value: " << outs[j].b << endl;
			}


			//ted prob�hl dotaz na v�echny hradla, ty aktualizovaly p��padn� stav sb�rnice a nyn� je pot�eba sb�rnici nastavit do nov�ho stavu
			//this->connections->cons[i]->setValue(b);
		}

		cout << endl;

		//prochazi jednotliv� propojen� a zjist� jejich stav (X, L, H) a nastav� nov� stav p��padn�, to v�e za pou�it� metod set/getValue
		
		elapsedTime += resolution;   //zde bude posun case dle planovani dalsi nadchazejici udalosti, udalosti bude 
		//vlastne nastaveni sbernice na nejakou konkretn� hodnotu, time manager teda bude p��jmat kdy to m� prov�st, 
		//co m� vlo�it na sb�rnici a na kterou sb�rnici to m� ud�lat
	}
}