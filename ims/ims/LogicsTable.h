/** @file LogicsTable.h*/

/*************************************\
*			  *
*	Auto�i:							  *
*		xpitri00 - Martin Pit��k	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: LogicsTable
Author: Martin Pit��k
Rev: 1
*/

#ifndef __LT_
#define __LT_

#include <vector>

#include "Logic.h"

using namespace std;

/**
* T��da seznamu v�ech hradel. 
*/
class LogicsTable
{
public:
	/**
	* Z�sk�n� instance dan� t��dy.
	* @return		LogicsTable*		instance
	*/
	static LogicsTable* instance();

protected:
	LogicsTable() {};

private:
	LogicsTable(LogicsTable const&);
	LogicsTable& operator=(LogicsTable const&);
	static LogicsTable* pInstance;

public:
	/**
	* Vektor jednotliv�ch hradel.
	*/
	vector<Logic*> logics;		//pro zjednoduseni pristupu

	/**
	* P�id�n� hradla.
	* @param		Logic*		hradlo
	*/
	void add(Logic *);

	/**
	* Vyhled�v�n� dan�ho hradla.
	* @param		string		jm�no
	* @return		Logic*		hradlo
	*/
	Logic *search(string);

	/**
	* Vymaz�n�.
	*/
	void clearAll();
};

#endif
