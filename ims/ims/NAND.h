/** @file AND.h*/

/*************************************\
*			  *
*	Autoøi:							  *
*		xpitri00 - Martin Pitøík	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: NAND
Author: Martin Pitøík
Rev: 1
*/

#include "Logic.h"

/**
* Tøída popisující hradlo NAND
*/
class NAND : public Logic
{
public:
	/**
	* Konstruktor
	*/
	NAND();

	/**
	* Vrací výstup hradla AND
	*
	* @return            bit
	*/
	virtual bit getY();
};
