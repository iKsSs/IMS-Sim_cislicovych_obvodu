/** @file CLKGen.h*/

/*************************************\
*			  *
*	Autoøi:							  *
*		xpitri00 - Martin Pitøík	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: CLKGen
Author: Martin Pitøík
Rev: 1
*/

#ifndef IMS__CLKGen
#define IMS__CLKGen

#include "Connect.h"
#include "Scheduler.h"

class CLKgen
{
private:
	Scheduler *scheduler;
public: 
	CLKgen() {}
	CLKgen(unsigned int, unsigned int, Connect *);
};

#endif