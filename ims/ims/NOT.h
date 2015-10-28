/** @file NOT.h*/

/*************************************\
*			  *
*	Autoøi:							  *
*		xpitri00 - Martin Pitøík	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: NOT
Author: Martin Pitøík
Rev: 1
*/


#include "Logic.h"

/**
* Tøída popisující hradlo NOT
*/
class NOT : public Logic
{
public:
	/**
	* Konstruktor
	*/
	NOT();

	/**
	* Vrací výstup hradla NOT
	*
	* @return            bit
	*/
	virtual bit getY();
};
