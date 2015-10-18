#include "SimCore.h"

SimCore::SimCore(SIM_TYPE, int time, int resolution)
{
	if (time < 0 || resolution < 0) throw("Chyba parametr� simulace.\n");
	if (time <= resolution) throw("Chyba parametr� simulace.\n");

	this->resolution = resolution;
	this->time = time;

	this->elapsedTime = 0;
}

void SimCore::run()									//a nebo parametry simulace tady m�sto do konstruktoru???
{
	while (this->elapsedTime <= this->time)			///time, resolution je ve stejnych jednotk�ch
	{
		

		elapsedTime += resolution;
	}
}