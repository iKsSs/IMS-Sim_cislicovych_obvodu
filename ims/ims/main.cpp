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
{	
	Token *token = new Token(argv[1]);
	Parser *parser = new Parser();

	try {
		while (token->getType() != ENDFILE)
		{
			token->getTokenData();
			//token->print();
			parser->processToken(token);
			parser->print();
		}

		SimCore sim(KLO, parser->getTime());
		sim.run();

		system("pause");
	}
	catch (const char* s)
	{
		cerr << "ERROR: " << s << endl;
		system("pause");
	}
	catch (...)
	{
		cerr << "ERROR: " << parser->getErrMsg() << endl;
		system("pause");
	}
}