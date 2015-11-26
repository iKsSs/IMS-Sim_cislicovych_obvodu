/** @file PlotCreator.h*/

/*************************************\
*			  *
*	Autoøi:							  *
*		xpitri00 - Martin Pitøík	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: PlotCreator
Author: Jakub Pastuszek
Rev: 1
*/

#ifndef __PLOTCREATOR_
#define __PLOTCREATOR_

#include <vector>
#include <fstream>
#include <string>

#include "Connections.h"
#include "Logic.h"

using namespace std;

typedef struct
{
	unsigned int time;			//v jakém èase
	bit b;						//hodnota
} PlotRecord;

typedef struct
{
	vector<PlotRecord> records;
	string name;
} PlotRecords;

class PlotCreator
{
private:
	ofstream file;
	ofstream script;
	vector<PlotRecords> records;
	string filename;
	unsigned int time;

public:
	PlotCreator(string, unsigned int);
	void writeState(unsigned int);
	void closeFile();
};

#endif
