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
Scheduler* Scheduler::pInstance = NULL;

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
	con5->setName("con5");
	con6->setName("con6");

	//con1->addToNode("and1.a");
	//con2->addToNode("and1.b");
	//con3->addToNode("or1.b");
	//con4->addToNode("and1.y");
	//con4->addToNode("or1.a");
	//con5->addToNode("or1.b");
	//con6->addToNode("or1.y");

	con1->addToNode(and1, 'a');
	con2->addToNode(and1, 'b');
	con3->addToNode(or1, 'b');
	con4->addToNode(and1, 'y');
	con4->addToNode(or1, 'a');
	con5->addToNode(or1, 'b');
	con6->addToNode(or1, 'y');

	con1->setValue(L);
	con2->setValue(H);
	con3->setValue(L);
	con4->setValue(L);
	con5->setValue(H);
	con6->setValue(L);

	ct->add(con1);
	ct->add(con2);
	ct->add(con3);
	ct->add(con4);
	ct->add(con5);
	ct->add(con6);

	//zde bude sestavena struktura se scanneru

	SimCore sim(KLO, 10, 1);

	sim.run();

	system("pause");

	//} test
}