#include "AND.h"
#include "OR.h"
#include "Connect.h"
#include "LogicsTable.h"
#include "SimCore.h"

#include <iostream>
#include <vector>

using namespace std;

LogicsTable* LogicsTable::pInstance = NULL;			//prvotni inicializace instance tabulky hradel

int main(void)
{	
	//test {
	LogicsTable *lt = LogicsTable::instance();
	
	
	Logic *and1 = new AND();
	Logic *or1 = new OR();

	and1->setName("and1");
	or1->setName("or1");

	Connect con1;
	Connect con2;
	Connect con3;
	Connect con4;
	Connect con5;

	con1.setName("con1");
	con2.setName("con2");
	con3.setName("con3");
	con4.setName("con4");
	con5.setName("con5");

	con1.setValue(L);
	con2.setValue(L);
	con3.setValue(L);
	con4.setValue(L);

	lt->add(and1);
	lt->add(or1);

	con1.addToNode("and1.a");
	con2.addToNode("and1.b");
	con3.addToNode("or1.b");
	con4.addToNode("and1.y");
	con4.addToNode("or1.a");
	con5.addToNode("or1.b");

	SimCore sim(KLO, 10, 1);

	sim.run();

	system("pause");

	//} test
}