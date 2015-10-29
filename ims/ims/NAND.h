/** @file AND.h*/

/*************************************\
*			  *
*	Auto�i:							  *
*		xpitri00 - Martin Pit��k	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: NAND
Author: Martin Pit��k
Rev: 1
*/

#include "Logic.h"

/**
* T��da popisuj�c� hradlo NAND
*/
class NAND : public Logic
{
public:
	/**
	* Konstruktor
	*/
	NAND();

	/**
	* Vrac� v�stup hradla AND
	*
	* @return            bit
	*/
	virtual bit getY();
};
