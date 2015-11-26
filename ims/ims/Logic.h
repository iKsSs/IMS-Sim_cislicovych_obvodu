/** @file Logic.h*/

/*************************************\
*			  *
*	Auto�i:							  *
*		xpitri00 - Martin Pit��k	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: Logic
Author: Martin Pit��k
Rev: 2
*/

#ifndef __LOGIC__
#define __LOGIC__

#include <string>

using namespace std;

/**
* V��tov� typ seskupuj�c� jednotliv� podporovan� logick� stavy.
*/
typedef enum 
{
	L, 
	H,
	X
}bit;

/**
* T��da definuj�c� rozhran� a z�kladn� funk�nost v�ech ostatn�ch logick�ch prvk�.
*/
class Logic
{
protected:
	bit Y, A, B;
	unsigned char delta;
	string name;

public:
	/**
	* Virtu�ln� metoda popisuj�c� chov�n� dan�ho logick�ho prvku. Tuto metodu je nutn� v odvozen�ch t��d�ch implementovat.
	* @return		bit			v�stup hradla
	*/
	virtual bit getY() = 0;
	
	/**
	* Nastaven� vstupu A.
	* @param		bit			A
	*/
	void setA(bit);

	/**
	* Nastaven� vstupu B.
	* @param		bit			B
	*/
	void setB(bit);

	/**
	* Nastaven� jm�na hradla.
	* @param		string		jm�no
	*/
	void setName(string);

	/**
	* Nastaven� zpo�d�n� hradla.
	* @param		unsigned char		zpo�d�n�
	*/
	void setDelta(unsigned char);

	/**
	* Z�sk�n� zpo�d�n� dan�ho hradla.
	* @return		unsigned char		zpo�d�n�
	*/
	unsigned char getDelta();

	/**
	* Z�sk�n� jm�na.
	* @return		string			jm�no
	*/
	string getName();
};

#endif
