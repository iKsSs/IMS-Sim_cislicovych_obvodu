#include <vector>
#include "Logic.h"

using namespace std;

#ifndef __LT_
#define __LT_

class LogicsTable
{
public:
	static LogicsTable* instance();

protected:
	LogicsTable() {};

private:
	LogicsTable(LogicsTable const&);
	LogicsTable& operator=(LogicsTable const&);
	static LogicsTable* pInstance;

public:
	vector<Logic*> logics;		//pro zjednoduseni pristupu

	void add(Logic *);
	Logic *search(string);
	void clearAll();
};

#endif;
