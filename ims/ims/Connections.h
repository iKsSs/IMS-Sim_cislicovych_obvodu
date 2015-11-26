/** @file Connections.h*/

/*************************************\
*			  *
*	Autoøi:							  *
*		xpitri00 - Martin Pitøík	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: Connections
Author: Martin Pitøík
Rev: 1
*/

#ifndef __CT_
#define __CT_

#include <vector>

#include "Connect.h"

using namespace std;

/**
* Tøída obsahující seznam všech propojení.
*/
class Connections
{
public:
	/**
	* Získání instance dané tøídy.
	* @return		Connections*		instance
	*/
	static Connections* instance();

protected:
	Connections() {};

private:
	Connections(Connections const&);
	Connections& operator=(Connections const&);
	static Connections* pInstance;

public:
	/**
	* Vektor obsahující jednotlivá propojení.
	*/
	vector<Connect*> cons;		//pro zjednoduseni pristupu

	/**
	* Pøidání propojení do seznamu.
	* @param		Connect*		propojení
	*/
	void add(Connect *);

	/**
	* Vyhledání propojení dle jeho jména.
	* @param		string			jméno
	* @return		Connect*		propojení
	*/
	Connect *search(string);

	/**
	* Vymazání všech položek.
	*/
	void clearAll();
};

#endif
