/** @file Connections.h*/

/*************************************\
*			  *
*	Auto�i:							  *
*		xpitri00 - Martin Pit��k	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: Connections
Author: Martin Pit��k
Rev: 1
*/

#ifndef __CT_
#define __CT_

#include <vector>

#include "Connect.h"

using namespace std;

/**
* T��da obsahuj�c� seznam v�ech propojen�.
*/
class Connections
{
public:
	/**
	* Z�sk�n� instance dan� t��dy.
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
	* Vektor obsahuj�c� jednotliv� propojen�.
	*/
	vector<Connect*> cons;		//pro zjednoduseni pristupu

	/**
	* P�id�n� propojen� do seznamu.
	* @param		Connect*		propojen�
	*/
	void add(Connect *);

	/**
	* Vyhled�n� propojen� dle jeho jm�na.
	* @param		string			jm�no
	* @return		Connect*		propojen�
	*/
	Connect *search(string);

	/**
	* Vymaz�n� v�ech polo�ek.
	*/
	void clearAll();
};

#endif
