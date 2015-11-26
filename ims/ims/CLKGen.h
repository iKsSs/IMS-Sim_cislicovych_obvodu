/** @file CLKGen.h*/

/*************************************\
*			  *
*	Auto�i:							  *
*		xpitri00 - Martin Pit��k	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: CLKGen
Author: Martin Pit��k
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