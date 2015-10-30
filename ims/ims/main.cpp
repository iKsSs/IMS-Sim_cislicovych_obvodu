#include "AND.h"
#include "OR.h"
#include "NOT.h"
#include "NAND.h"

#include "Connect.h"
#include "LogicsTable.h"
#include "Connections.h"
#include "SimCore.h"
#include "Scheduler.h"
#include "PlotCreator.h"
#include "CLKgen.h"

#include <iostream>
#include <vector>

using namespace std;

LogicsTable* LogicsTable::pInstance = NULL;			//prvotni inicializace instance tabulky hradel
Connections* Connections::pInstance = NULL;			//prvotni inicializace instance tabulky propojeni 
Scheduler* Scheduler::pInstance = NULL;				//prvotni incicializace instance plánovaèe

string netlist;
string simout;

int main(void)
{	
	//test {
	LogicsTable *lt = LogicsTable::instance();
	Connections *ct = Connections::instance();
	
	Logic *nand1 = new NAND();
	Logic *nand2 = new NAND();

	nand1->setName("nand1");
	nand2->setName("nand2");

	nand1->setDelta(1);
	nand2->setDelta(1);

	lt->add(nand1);
	lt->add(nand2);

	Connect *con1 = new Connect();
	Connect *con2 = new Connect();
	Connect *con3 = new Connect();
	Connect *con4 = new Connect();
	Connect *clk = new Connect();

	con1->setName("con1");
	con2->setName("con2");
	con3->setName("con3");
	con4->setName("con4");
	clk->setName("clk");

	con1->addToNode(nand1, 'a');
	con2->addToNode(nand2, 'b');
	con3->addToNode(nand1, 'y');
	con3->addToNode(nand2, 'a');
	con4->addToNode(nand2, 'y');
	con4->addToNode(nand1, 'b');

	//prvotni inicializace sbìrnic do plánovaèe

	CLKgen clkgen(2, 10, clk);

	Scheduler* scheduler = Scheduler::instance();

	SchedulerEvent *s1 = new SchedulerEvent;
	s1->b = L;
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
	s4->b = H;
	s4->c = con4;
	s4->time = 0;
	scheduler->addEvent(s4);

	ct->add(con1);
	ct->add(con2);
	ct->add(con3);
	ct->add(con4);
	ct->add(clk);

	//zde bude sestavena struktura se scanneru

	SimCore sim(KLO, 10, 1);
	
	sim.run();

	//system("pause");

	//} test
}