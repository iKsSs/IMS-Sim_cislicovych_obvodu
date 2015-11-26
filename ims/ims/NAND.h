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

#ifndef IMS__NAND
#define IMS__NAND

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
	NAND() : Logic() {}

	/**
	* Vrac� v�stup hradla AND
	*
	* @return            bit
	*/
	virtual bit getY();
};

#endif