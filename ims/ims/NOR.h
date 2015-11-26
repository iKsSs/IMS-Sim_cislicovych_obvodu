/** @file NOR.h*/

/*************************************\
*			  *
*	Auto�i:							  *
*		xpitri00 - Martin Pit��k	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: NOR
Author: Martin Pit��k
Rev: 1
*/

#ifndef IMS__NOR
#define IMS__NOR

#include "Logic.h"

/**
* T��da popisuj�c� hradlo NOR
*/
class NOR : public Logic
{
public:
	/**
	* Konstruktor
	*/
	NOR() : Logic() {}

	/**
	* Vrac� v�stup hradla NOR
	*
	* @return            bit
	*/
	virtual bit getY();
};

#endif