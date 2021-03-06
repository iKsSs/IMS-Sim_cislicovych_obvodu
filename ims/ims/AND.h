/** @file AND.h*/

/*************************************\
*			  *
*	Auto�i:							  *
*		xpitri00 - Martin Pit��k	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: AND
Author: Martin Pit��k
Rev: 1
*/

#ifndef IMS__AND
#define IMS__AND

#include "Logic.h"

/**
* T��da popisuj�c� hradlo AND
*/
class AND : public Logic
{
public:
	/**
	* Konstruktor
	*/
	AND() : Logic() {}

	/**
	* Vrac� v�stup hradla AND
	*
	* @return            bit
	*/
	virtual bit getY();
};

#endif