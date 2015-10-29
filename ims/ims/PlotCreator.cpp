#include "PlotCreator.h"

PlotCreator::PlotCreator(string filename)
{
	this->file.open(filename);

	Connections *c = Connections::instance();

	int count = c->cons.size();			//zjist�, kolik connections se sleduje
	this->records.resize(count);		//a nastav� odpov�daj�c� sledovac� historii

	for (int i = 0; i < count; ++i)
	{
		this->records[i].name = c->cons[i]->getName();
	}
}

void PlotCreator::writeState(unsigned int time)
{
	Connections *c = Connections::instance();
	
	int i;
	int count = c->cons.size();

	//zjisti stavy v�ech sb�rnic v dan�m �ase a zap�e je do historie

	for (i = 0; i < count; ++i)
	{
		Connect *tmp = c->cons[i];			//vyt�hne stavy propojen� a poznamen� si je
		PlotRecord r;
		r.b = tmp->getValue();
		r.time = time;

		this->records[i].records.push_back(r);
	}
}

void PlotCreator::closeFile()
{
	int i;
	int count = this->records.size();

	for (i = 0; i < count; ++i)
	{
		PlotRecords r = this->records[i];

		this->file << "#" << endl;
		this->file << "\"" << r.name << "\"" << endl;

		int j;
		int count2 = r.records.size();

		for (j = 0; j < count2; ++j)
		{
			PlotRecord rr = r.records[j];

			this->file << rr.time << " " << rr.b << endl;
		}

		this->file << endl << endl;
	}

	this->file.close();
}
