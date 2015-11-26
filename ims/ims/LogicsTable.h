/** @file LogicsTable.h*/

/*************************************\
*			  *
*	Autoøi:							  *
*		xpitri00 - Martin Pitøík	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: LogicsTable
Author: Martin Pitøík
Rev: 1
*/


#include <vector>
#include "Logic.h"

using namespace std;

#ifndef __LT_
#define __LT_

/**
* Tøída seznamu všech hradel. 
*/
class LogicsTable
{
public:
	/**
	* Získání instance dané tøídy.
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
	* Vektor jednotlivých hradel.
	*/
	vector<Logic*> logics;		//pro zjednoduseni pristupu

	/**
	* Pøidání hradla.
	* @param		Logic*		hradlo
	*/
	void add(Logic *);

	/**
	* Vyhledávání daného hradla.
	* @param		string		jméno
	* @return		Logic*		hradlo
	*/
	Logic *search(string);

	/**
	* Vymazání.
	*/
	void clearAll();
};

#endif
