/** @file OR.h*/

/*************************************\
*			  *
*	Auto�i:							  *
*		xpitri00 - Martin Pit��k	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: OR
Author: Martin Pit��k
Rev: 1
*/

#ifndef IMS__OR
#define IMS__OR

#include "Logic.h"

/**
* T��da popisuj�c� hradlo OR
*/
class OR : public Logic
{
public:
	/**
	* Konstruktor
	*/
	OR();

	/**
	* Vrac� v�stup hradla NOT
	*
	* @return            bit
	*/
	virtual bit getY();
};

#endif