/** @file Connect.h*/

/*************************************\
*			  *
*	Autoøi:							  *
*		xpitri00 - Martin Pitøík	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: Connect
Author: Martin Pitøík
Rev: 3
*/


#include <vector>
#include <string>

#include "Logic.h"

using namespace std;

#ifndef __CONNECT_
#define __CONNECT_

/**
* Struktura popisující jednotlivé zmìny logické hodnoty v èase.
*/
typedef struct
{
	unsigned int time;		//kdy
	bit b;					//na jakou hodnotu
	//int i;				//koho aktualozovat (index do connections)
	void *c;				//koho aktualizovat (void ukazatel je zde použít, protože ještì není známa tøída connect, nicménì tøída connect tuto strukturu využívá a proto musí být uvedena pøed ní
	void *l;					//kdo o zmenu pozadal
} bits;

/**
* Struktura popisující pøipojení konkrétního pinu hradla k spojení.
*/
typedef struct
{
	Logic *l;
	char pin;
} NodeItem;

/**
* Tøída popisující spojení jednotlivých pinù hradel.
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
	* Bezparametrický konstruktor.
	*/
	Connect();

	/**
	* Nastavení hodnoty na daném spojení. Touto hodnotou jsou potom inicializována všechna hradla pøipojená k propojení.
	* @param		bit			nastavení stavu propojení
	*/
	void setValue(bit);

	/**
	* Vrací hodnotu daného propojení.
	* @return		bit			hodnota propojení
	*/
	bit getValue();  //return state

	/**
	* Vrací hodnotu daného propojení v èase.
	* @return vector<bits*>		hodnoty propojení v budoucím èase
	*/
	vector<bits*> getNextValues(); //vrací hodnoty sbìrnice v následujícíh èasech, jak se vyvolají události na hradlech, po uplynutí zpoždìní
	
	/**
	* Nastaví jméno daného propojení.
	* @param		string		jméno
	*/
	void setName(string);

	/**
	* Získá jméno daného propojení.
	* @return		string		jméno
	*/
	string getName();
	
	/**
	* Pøidá pin hradla do daného propojení.
	* @param		Logic*		hradlo implementující rozhraní Logic
	* @param		char		pin (a/b/y)
	*/
	void addToNode(Logic*, char);
};

#endif
