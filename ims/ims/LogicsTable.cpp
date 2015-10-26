#include "LogicsTable.h"

LogicsTable* LogicsTable::instance()
{
	if (!pInstance)
	{
		pInstance = new LogicsTable;
	}

	return pInstance;
}

void LogicsTable::add(Logic *l)
{
	this->logics.push_back(l);
}

Logic* LogicsTable::search(string name)
{
	int count = this->logics.size();
	int i;

	for (int i = 0; i < count; ++i)
	{
		Logic* tmp = this->logics[i];

		if (tmp->getName() == name)
			return tmp;
	}

	return NULL;
}

void LogicsTable::clearAll()
{
	this->logics.clear();
}
