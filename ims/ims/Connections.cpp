#include "Connections.h"

Connections* Connections::instance()
{
	if (!pInstance)
	{
		pInstance = new Connections;
	}

	return pInstance;
}

void Connections::add(Connect *c)
{
	this->cons.push_back(c);
}

Connect* Connections::search(string name)
{
	int count = this->cons.size();
	int i;

	for (int i = 0; i < count; ++i)
	{
		Connect* tmp = this->cons[i];

		if (tmp->getName() == name)
			return tmp;
	}

	return NULL;
}

void Connections::clearAll()
{
	this->cons.clear();
}

