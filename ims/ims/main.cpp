#include "AND.h"
#include "OR.h"
#include "Connect.h"
#include "LogicsTable.h"

#include <iostream>
#include <vector>

using namespace std;

LogicsTable* LogicsTable::pInstance = NULL;			//prvotni inicializace instance tabulky hradel

int main(void)
{	
	LogicsTable *lt = LogicsTable::instance();
	LogicsTable *test = LogicsTable::instance();

	Connect cc;
	
	cout << "test" << endl;

	Logic *and1 = new AND();
	and1->setName("and1");

	lt->logics.push_back(and1);

	cout << test->logics[0]->getName();

	cc.getValue();

	system("pause");
}