/** @file NOR.h*/

/*************************************\
*			  *
*	Autoøi:							  *
*		xpitri00 - Martin Pitøík	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: NOR
Author: Martin Pitøík
Rev: 1
*/

#ifndef IMS__NOR
#define IMS__NOR

#include "Logic.h"

/**
* Tøída popisující hradlo NOR
*/
class NOR : public Logic
{
public:
	/**
	* Konstruktor
	*/
	NOR() : Logic() {}

	/**
	* Vrací výstup hradla NOR
	*
	* @return            bit
	*/
	virtual bit getY();
};

#endif