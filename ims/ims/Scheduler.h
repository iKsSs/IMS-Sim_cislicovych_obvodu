/** @file Scheduler.h*/

/*************************************\
*			  *
*	Auto�i:							  *
*		xpitri00 - Martin Pit��k	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: Scheduler
Author: Martin Pit��k
Rev: 2
*/

#include "Logic.h"

#include <queue>
#include <vector>

using namespace std;

/**
* Struktura popisuj�c� ud�lost.
*/
typedef struct
{	
	unsigned int time;
	bit b;
	void *c;
}
SchedulerEvent;

/**
* T��da popisuj�c� pl�nova�.
*/
class Scheduler
{
public:
	/**
	* Z�sk�n� instance dan� t��dy.
	* @return		Scheduler*			instance
	*/
	static Scheduler* instance();

protected:
	Scheduler() {};

private:
	Scheduler(Scheduler const&);
	Scheduler& operator=(Scheduler const&);
	static Scheduler* pInstance;

public:
	//queue<SchedulerEvent *> q;

	/**
	* Vektor ud�lost�.
	*/
	vector<SchedulerEvent*> q;

	/**
	* P�id�n� nov� ud�losti.
	* @param		SchedulerEvent*			ud�lost
	*/
	void addEvent(SchedulerEvent *);

	/**
	* Vr�cen� nejbli��� a nejd��v�ji mo�n� napl�novan� ud�losti.
	* @return		SchedulerEvent*			ud�lost
	*/
	SchedulerEvent *getNextEvent();

	/**
	* Test, zda existuj� je�t� n�jak� ud�losti.
	* @return		bool		
	*/
	bool isEmpty();
};
