/** @file Scheduler.h*/

/*************************************\
*			  *
*	Autoøi:							  *
*		xpitri00 - Martin Pitøík	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: Scheduler
Author: Martin Pitøík
Rev: 2
*/

#ifndef __SCHEDULER_
#define __SCHEDULER_

#include "Logic.h"

#include <queue>
#include <vector>

using namespace std;

/**
* Struktura popisující událost.
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
* Tøída popisující plánovaè.
*/
class Scheduler
{
public:
	/**
	* Získání instance dané tøídy.
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
	* Vektor událostí.
	*/
	vector<SchedulerEvents*> q;

	/**
	* Pøidání nové události.
	* @param		SchedulerEvent*			událost
	*/
	void addEvent(SchedulerEvent *);

	/**
	* Vrácení nejbližší a nejdøívìji možné naplánované události.
	* @return		SchedulerEvent*			událost
	*/
	SchedulerEvents* getNextEvents();

	void popEvent();

	/**
	* Test, zda existují ještì nìjaké události.
	* @return		bool		
	*/
	bool isEmpty();
};

#endif
