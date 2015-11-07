#include "AND.h"
#include "OR.h"
#include "NOR.h"
#include "NOT.h"
#include "NAND.h"

#include "Connect.h"
#include "LogicsTable.h"
#include "Connections.h"
#include "SimCore.h"
#include "Scheduler.h"
#include "PlotCreator.h"
#include "CLKgen.h"
#include "scanner.h"
#include "parser.h"

#include <iostream>
#include <vector>

using namespace std;

LogicsTable* LogicsTable::pInstance = NULL;			//prvotni inicializace instance tabulky hradel
Connections* Connections::pInstance = NULL;			//prvotni inicializace instance tabulky propojeni 
Scheduler* Scheduler::pInstance = NULL;				//prvotni incicializace instance plánovaèe

string netlist;
string simout;

int main(int argc, const char* argv[])
{	/*
	Token *token = new Token(argv[1]);
	Parser *parser = new Parser();

	while (token->getType() != ENDFILE)
	{
		token->getTokenData();
		//token->print();
		parser->processToken(token);
		parser->print();
	}
	
	SimCore sim(KLO, parser->getTime());
	sim.run();
	*/
	LogicsTable *lt = LogicsTable::instance();				// OK
	Connections *ct = Connections::instance();
	
	Logic *nand1 = new NAND();									// OK
	Logic *nand2 = new NAND();

	nand1->setName("nand1");									// DEPENDENCY OK
	nand2->setName("nand2");

	nand1->setDelta(1);											// DEPENDENCY OK
	nand2->setDelta(1);

	lt->add(nand1);												// DEPENDENCY OK
	lt->add(nand2);

	Connect *con1 = new Connect();								// OK
	Connect *con2 = new Connect();
	Connect *con3 = new Connect();
	Connect *con4 = new Connect();
	Connect *clk = new Connect();								// OK

	con1->setName("!S");										// OK - VYKRICNIKY
	con2->setName("'R");
	con3->setName("Q");
	con4->setName("!Q");
	clk->setName("clk");

	con1->addToNode(nand1, 'a');								// NOT YET
	con2->addToNode(nand2, 'b');
	con3->addToNode(nand1, 'y');
	con3->addToNode(nand2, 'a');
	con4->addToNode(nand2, 'y');
	con4->addToNode(nand1, 'b');

	//prvotni inicializace sbìrnic do plánovaèe

	CLKgen clkgen(2, 10, clk);									// OK but?

	Scheduler* scheduler = Scheduler::instance();				// OK

	SchedulerEvent *s1 = new SchedulerEvent;					// OK
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

	//KO je ve stavu SET

	//nastavim pamatovani stavu

	SchedulerEvent *s5 = new SchedulerEvent;
	s5->b = H;
	s5->c = con1;
	s5->time = 6;
	scheduler->addEvent(s5);

	SchedulerEvent *s6 = new SchedulerEvent;
	s6->b = H;
	s6->c = con2;
	s6->time = 6;
	scheduler->addEvent(s6);

	ct->add(con1);												// OK
	ct->add(con2);
	ct->add(con3);
	ct->add(con4);
	ct->add(clk);

	//zde bude sestavena struktura se scanneru

	SimCore sim(KLO, 10);										// OK
	
	sim.run();

	system("pause");
}