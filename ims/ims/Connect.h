/** @file Connect.h*/

/*************************************\
*			  *
*	Auto�i:							  *
*		xpitri00 - Martin Pit��k	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: Connect
Author: Martin Pit��k
Rev: 3
*/


#include <vector>
#include <string>

#include "Logic.h"

using namespace std;

#ifndef __CONNECT_
#define __CONNECT_

/**
* Struktura popisuj�c� jednotliv� zm�ny logick� hodnoty v �ase.
*/
typedef struct
{
	unsigned int time;		//kdy
	bit b;					//na jakou hodnotu
	//int i;				//koho aktualozovat (index do connections)
	void *c;				//koho aktualizovat (void ukazatel je zde pou��t, proto�e je�t� nen� zn�ma t��da connect, nicm�n� t��da connect tuto strukturu vyu��v� a proto mus� b�t uvedena p�ed n�
	void *l;					//kdo o zmenu pozadal
} bits;

/**
* Struktura popisuj�c� p�ipojen� konkr�tn�ho pinu hradla k spojen�.
*/
typedef struct
{
	Logic *l;
	char pin;
} NodeItem;

/**
* T��da popisuj�c� spojen� jednotliv�ch pin� hradel.
*/
class Connect
{
private:
	bit state;
	vector<NodeItem> nodePins;
	string name;
	bool changed;
public:
	/**
	* Bezparametrick� konstruktor.
	*/
	Connect();

	/**
	* Nastaven� hodnoty na dan�m spojen�. Touto hodnotou jsou potom inicializov�na v�echna hradla p�ipojen� k propojen�.
	* @param		bit			nastaven� stavu propojen�
	*/
	void setValue(bit);

	/**
	* Vrac� hodnotu dan�ho propojen�.
	* @return		bit			hodnota propojen�
	*/
	bit getValue();  //return state

	/**
	* Vrac� hodnotu dan�ho propojen� v �ase.
	* @return vector<bits*>		hodnoty propojen� v budouc�m �ase
	*/
	vector<bits*> getNextValues(); //vrac� hodnoty sb�rnice v n�sleduj�c�h �asech, jak se vyvolaj� ud�losti na hradlech, po uplynut� zpo�d�n�
	
	/**
	* Nastav� jm�no dan�ho propojen�.
	* @param		string		jm�no
	*/
	void setName(string);

	/**
	* Z�sk� jm�no dan�ho propojen�.
	* @return		string		jm�no
	*/
	string getName();
	
	/**
	* P�id� pin hradla do dan�ho propojen�.
	* @param		Logic*		hradlo implementuj�c� rozhran� Logic
	* @param		char		pin (a/b/y)
	*/
	void addToNode(Logic*, char);
};

#endif
