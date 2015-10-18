#include "SimCore.h"

SimCore::SimCore(SIM_TYPE, int time, int resolution)
{
	if (time < 0 || resolution < 0) throw("Chyba parametrù simulace.\n");
	if (time <= resolution) throw("Chyba parametrù simulace.\n");

	this->resolution = resolution;
	this->time = time;

	this->elapsedTime = 0;
}

void SimCore::run()									//a nebo parametry simulace tady místo do konstruktoru???
{
	while (this->elapsedTime <= this->time)			///time, resolution je ve stejnych jednotkách
	{
		

		elapsedTime += resolution;
	}
}