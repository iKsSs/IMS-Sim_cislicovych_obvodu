/** @file SimCore.h*/

/*************************************\
*			  *
*	Auto�i:							  *
*		xpitri00 - Martin Pit��k	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: SimCore
Author: Martin Pit��k
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
* Struktura popisuj�c� typ simulovan�ho obvodu.
*/
typedef enum
{
	SLO,
	KLO
}SIM_TYPE;

/**
* T��da simul�toru
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
	* Vytvo�en� nov� simulace - konstruktor.
	* @param		SIM_TYPE		typ simulace
	* @param		int				�as simulace
	* @param		int				rozli�en� simulace (nen� pou�ito)
	*/
	SimCore(SIM_TYPE, int);			//odkazy od tabulek si veme

	/**
	* Spu�t�n� simulace
	*/
	void run(std::string);							//spu�t�n� simulace
};

#endif