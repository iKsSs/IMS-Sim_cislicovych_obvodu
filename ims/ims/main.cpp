#include "AND.h"
#include "OR.h"
#include "NOT.h"
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
	Logic *and2 = new AND();
	Logic *not1 = new NOT();
	Logic *not2 = new NOT();

	and1->setName("and1");
	and2->setName("and2");
	not1->setName("not1");
	not2->setName("not2");

	and1->setDelta(2);
	and2->setDelta(2);
	not1->setDelta(1);
	not2->setDelta(1);

	lt->add(and1);
	lt->add(and2);
	lt->add(not1);
	lt->add(not2);

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
	con5->setName("con5");
	con6->setName("con6");

	con1->addToNode(and1, 'a');
	con2->addToNode(and2, 'b');
	con3->addToNode(not1, 'a');
	con3->addToNode(and1, 'y');
	con4->addToNode(not2, 'a');
	con4->addToNode(and2, 'y');
	con5->addToNode(not1, 'y');
	con5->addToNode(and2, 'a');
	con6->addToNode(not2, 'y');
	con6->addToNode(and1, 'b');

	//prvotni inicializace sbìrnic do plánovaèe

	Scheduler* scheduler = Scheduler::instance();

	SchedulerEvent *s1 = new SchedulerEvent;
	s1->b = L;
	s1->c = con1;
	s1->time = 0;
	scheduler->addEvent(s1);

	SchedulerEvent *s2 = new SchedulerEvent;
	s2->b = L;
	s2->c = con2;
	s2->time = 0;
	scheduler->addEvent(s2);

	SchedulerEvent *s3 = new SchedulerEvent;
	s3->b = H;
	s3->c = con3;
	s3->time = 0;
	scheduler->addEvent(s3);

	SchedulerEvent *s4 = new SchedulerEvent;
	s4->b = L;
	s4->c = con4;
	s4->time = 0;
	scheduler->addEvent(s4);

	SchedulerEvent *s5 = new SchedulerEvent;
	s5->b = L;
	s5->c = con5;
	s5->time = 0;
	scheduler->addEvent(s5);

	SchedulerEvent *s6 = new SchedulerEvent;
	s6->b = H;
	s6->c = con6;
	s6->time = 0;
	scheduler->addEvent(s6);

	ct->add(con1);
	ct->add(con2);
	ct->add(con3);
	ct->add(con4);
	ct->add(con5);
	ct->add(con6);

	//zde bude sestavena struktura se scanneru

	SimCore sim(KLO, 20, 1);

	sim.run();

	system("pause");

	//} test
}