/** @file Logic.h*/

/*************************************\
*			  *
*	Autoøi:							  *
*		xpitri00 - Martin Pitøík	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: Logic
Author: Martin Pitøík
Rev: 2
*/

#ifndef __LOGIC__
#define __LOGIC__

#include <string>

using namespace std;

/**
* Výètový typ seskupující jednotlivé podporované logické stavy.
*/
typedef enum 
{
	L, 
	H,
	X
}bit;

/**
* Tøída definující rozhraní a základní funkènost všech ostatních logických prvkù.
*/
class Logic
{
protected:
	bit Y, A, B;
	unsigned char delta;
	string name;

public:
	/**
	* Virtuální metoda popisující chování daného logického prvku. Tuto metodu je nutné v odvozených tøídách implementovat.
	* @return		bit			výstup hradla
	*/
	virtual bit getY() = 0;
	
	/**
	* Nastavení vstupu A.
	* @param		bit			A
	*/
	void setA(bit);

	/**
	* Nastavení vstupu B.
	* @param		bit			B
	*/
	void setB(bit);

	/**
	* Nastavení jména hradla.
	* @param		string		jméno
	*/
	void setName(string);

	/**
	* Nastavení zpoždìní hradla.
	* @param		unsigned char		zpoždìní
	*/
	void setDelta(unsigned char);

	/**
	* Získání zpoždìní daného hradla.
	* @return		unsigned char		zpoždìní
	*/
	unsigned char getDelta();

	/**
	* Získání jména.
	* @return		string			jméno
	*/
	string getName();
};

#endif
