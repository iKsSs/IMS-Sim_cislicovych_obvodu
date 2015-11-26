/** @file SimCore.h*/

/*************************************\
*			  *
*	Autoøi:							  *
*		xpitri00 - Martin Pitøík	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: SimCore
Author: Martin Pitøík
Rev: 1
*/

#ifndef __SIMCORE_
#define __SIMCORE_

#include <iostream>
#include <string>
#include <vector>

#include "Logic.h"
#include "Connections.h"
#include "LogicsTable.h"
#include "Scheduler.h"
#include "PlotCreator.h"

using namespace std;

/**
* Struktura popisující typ simulovaného obvodu.
*/
typedef enum
{
	SLO,
	KLO
}SIM_TYPE;

/**
* Tøída simulátoru
*/
class SimCore
{
private:
	unsigned int time;
	unsigned int elapsedTime;
	LogicsTable *logicTable;
	Connections *connections;

	void printResult();
public:
	/**
	* Vytvoøení nové simulace - konstruktor.
	* @param		SIM_TYPE		typ simulace
	* @param		int				èas simulace
	* @param		int				rozlišení simulace (není použito)
	*/
	SimCore(SIM_TYPE, int);			//odkazy od tabulek si veme

	/**
	* Spuštìní simulace
	*/
	void run(std::string);							//spuštìní simulace
};

#endif