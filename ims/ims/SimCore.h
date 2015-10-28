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

#include <string>
#include <vector>

#include "Logic.h"
#include "Connections.h"
#include "LogicsTable.h"

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
	int resolution;
	int time;
	int elapsedTime;
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
	SimCore(SIM_TYPE, int, int);		//odkazy od tabulek si veme

	/**
	* Spu�t�n� simulace
	*/
	void run();							//spu�t�n� simulace
};