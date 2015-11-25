#ifndef IMS__NOR
#define IMS__NOR

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
	NOR();

	/**
	* Vrací výstup hradla NOR
	*
	* @return            bit
	*/
	virtual bit getY();
};

#endif