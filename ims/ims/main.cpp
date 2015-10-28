#include "AND.h"
#include "OR.h"
#include "Connect.h"
#include "LogicsTable.h"
#include "Connections.h"
#include "SimCore.h"
#include "Scheduler.h"

#include <iostream>
#include <vector>

using namespace std;

LogicsTable* LogicsTable::pInstance = NULL;			//prvotni inicializace instance tabulky hradel
Connections* Connections::pInstance = NULL;			//prvotni inicializace instance tabulky propojeni 
Scheduler* Scheduler::pInstance = NULL;				//prvotni incicializace instance plánovaèe

int main(void)
{	
	//test {
	LogicsTable *lt = LogicsTable::instance();
	Connections *ct = Connections::instance();
	
	Logic *and1 = new AND();
	Logic *or1 = new OR();

	and1->setName("and1");
	or1->setName("or1");

	and1->setDelta(4);
	or1->setDelta(2);

	lt->add(and1);
	lt->add(or1);

	Connect *con1 = new Connect();
	Connect *con2 = new Connect();
	Connect *con3 = new Connect();
	Connect *con4 = new Connect();
	Connect *con5 = new Connect();
	Connect *con6 = new Connect();

	con1->setName("con1");
	con2->setName("con2");
	con3->setName("con3");
	con4->setName("con4");
	con6->setName("con6");

	con1->addToNode(and1, 'a');
	con2->addToNode(and1, 'b');
	con3->addToNode(or1, 'b');
	con4->addToNode(and1, 'y');
	con4->addToNode(or1, 'a');
	con6->addToNode(or1, 'y');

	Scheduler* scheduler = Scheduler::instance();

	SchedulerEvent *s1 = new SchedulerEvent;
	s1->b = H;
	s1->c = con1;
	s1->time = 0;
	scheduler->addEvent(s1);

	SchedulerEvent *s2 = new SchedulerEvent;
	s2->b = H;
	s2->c = con2;
	s2->time = 0;
	scheduler->addEvent(s2);

	SchedulerEvent *s3 = new SchedulerEvent;
	s3->b = L;
	s3->c = con3;
	s3->time = 0;
	scheduler->addEvent(s3);

	SchedulerEvent *s4 = new SchedulerEvent;
	s4->b = L;
	s4->c = con4;
	s4->time = 0;
	scheduler->addEvent(s4);

	SchedulerEvent *s6 = new SchedulerEvent;
	s6->b = L;
	s6->c = con6;
	s6->time = 0;
	scheduler->addEvent(s6);

	ct->add(con1);
	ct->add(con2);
	ct->add(con3);
	ct->add(con4);
	ct->add(con6);

	//zde bude sestavena struktura se scanneru

	SimCore sim(KLO, 10, 1);

	sim.run();

	system("pause");

	//} test
}