/** @file AND.h*/

/*************************************\
*			  *
*	Autoøi:							  *
*		xpitri00 - Martin Pitøík	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: AND
Author: Martin Pitøík
Rev: 1
*/

#include "Logic.h"

/**
* Tøída popisující hradlo AND
*/
class AND : public Logic
{
public:
	/**
	* Konstruktor
	*/
	AND();

	/**
	* Vrací výstup hradla AND
	*
	* @return            bit
	*/
	virtual bit getY();
};
