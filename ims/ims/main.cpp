#include "AND.h"
#include "NAND.h"
#include "OR.h"
#include "NOR.h"
#include "NOT.h"

#include "CLKGen.h"
#include "Connect.h"
#include "Connections.h"
#include "LogicsTable.h"
#include "parser.h"
#include "PlotCreator.h"
#include "scanner.h"
#include "Scheduler.h"
#include "SimCore.h"

#include <iostream>
#include <vector>
#include <sys/stat.h>

using namespace std;

LogicsTable* LogicsTable::pInstance = NULL;			//prvotni inicializace instance tabulky hradel
Connections* Connections::pInstance = NULL;			//prvotni inicializace instance tabulky propojeni 
Scheduler* Scheduler::pInstance = NULL;				//prvotni incicializace instance plánovaèe

string netlist;
string simout;

int main(int argc, const char* argv[])
{	
	Token *token;
	Parser *parser;

	try {
		if (argc < 2) { throw "wrong argument"; }

		struct stat buffer;
		string file = argv[1];
	
		if (stat(file.c_str(), &buffer) != 0)
		{
			throw "file unreachable";
		}

		token = new Token(file.c_str());
		parser = new Parser();
	
		while (token->getType() != ENDFILE)
		{
			token->getTokenData();
			//token->print();
			parser->processToken(token);
			//parser->print();
		}

		SimCore sim(KLO, parser->getTime());
		sim.run(file);

		delete token;
		delete parser;
	}
	catch (const char* s)
	{
		cerr << "ERROR: " << s << endl;
	}
	catch (...)
	{
		cerr << "ERROR: " << parser->getErrMsg() << endl;
	}
}