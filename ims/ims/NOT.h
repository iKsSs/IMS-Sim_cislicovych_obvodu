/** @file NOT.h*/

/*************************************\
*			  *
*	Auto�i:							  *
*		xpitri00 - Martin Pit��k	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: NOT
Author: Martin Pit��k
Rev: 1
*/

#ifndef IMS__NOT
#define IMS__NOT

#include "Logic.h"

/**
* T��da popisuj�c� hradlo NOT
*/
class NOT : public Logic
{
public:
	/**
	* Konstruktor
	*/
	NOT() : Logic() {}

	/**
	* Vrac� v�stup hradla NOT
	*
	* @return            bit
	*/
	virtual bit getY();
};

#endif