/** @file OR.h*/

/*************************************\
*			  *
*	Autoøi:							  *
*		xpitri00 - Martin Pitøík	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: OR
Author: Martin Pitøík
Rev: 1
*/

#ifndef IMS__OR
#define IMS__OR

#include "Logic.h"

/**
* Tøída popisující hradlo OR
*/
class OR : public Logic
{
public:
	/**
	* Konstruktor
	*/
	OR();

	/**
	* Vrací výstup hradla NOT
	*
	* @return            bit
	*/
	virtual bit getY();
};

#endif