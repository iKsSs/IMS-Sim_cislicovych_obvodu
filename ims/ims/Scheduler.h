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

#ifndef __SCHEDULER_
#define __SCHEDULER_

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
	void *l;
}
SchedulerEvent;

typedef struct
{
	vector<SchedulerEvent*> events;
	unsigned int time;
}
SchedulerEvents;

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
	unsigned int min_index;

public:
	//queue<SchedulerEvent *> q;

	/**
	* Vektor ud�lost�.
	*/
	vector<SchedulerEvents*> q;

	/**
	* P�id�n� nov� ud�losti.
	* @param		SchedulerEvent*			ud�lost
	*/
	void addEvent(SchedulerEvent *);

	/**
	* Vr�cen� nejbli��� a nejd��v�ji mo�n� napl�novan� ud�losti.
	* @return		SchedulerEvent*			ud�lost
	*/
	SchedulerEvents* getNextEvents();

	void popEvent();

	/**
	* Test, zda existuj� je�t� n�jak� ud�losti.
	* @return		bool		
	*/
	bool isEmpty();
};

#endif
