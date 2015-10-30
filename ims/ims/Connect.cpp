#include "Connect.h"
#include "LogicsTable.h"

//state v konstruktoru nastavit na X

Connect::Connect()
{
	this->state = X;
	this->changed = false;
}

vector<bits*> Connect::getNextValues()
{
	//LogicsTable *lt = LogicsTable::instance();
	//unsigned int count = this->pins.size();
	unsigned int count = this->nodePins.size();
	unsigned int i;
	vector<bits*> nextValue;

	for (i = 0; i < count; ++i)
	{
		//string tmp = pins[i];
		//char pin = tmp[tmp.length() - 1];
		//string name = tmp.substr(0, tmp.length() - 2);

		NodeItem tmp = this->nodePins[i];

		if (tmp.pin == 'y')
		{
			//Logic *ll = lt->search(name);

			//if (ll != NULL)
			//{
			bits *val = new bits;
			//val.time = ll->getDelta();
			val->time = tmp.l->getDelta();
			//val.b = ll->getY();
			val->b = tmp.l->getY();
			val->c = this;

			//existuje už záznam z tímto èasem?
			unsigned int count2 = nextValue.size();
			unsigned int j;

			if (count2 == 0)		//vklada prvni prvek
			{
				nextValue.push_back(val);
			}

			for (j = 0; j < count2; ++j)
			{
				if (nextValue[j]->time == val->time)		//záznam existuje, jen kontroluji, zda se hradla, které v tento èas vkládají, shodla
				{
					if ((nextValue[j]->b == X) || (nextValue[j]->b == L && val->b == L) || (nextValue[j]->b == H && val->b == H))
					{
						nextValue[j]->b = val->b;
					}
					else
					{
						throw("Chyba bìhem simulace, nedefinovaný stav na sbìrnici.\n");
					}
				}
				else //záznam s tímto èasem neexistuje
				{
					nextValue.push_back(val);	//tak jej vložím
				}
			}
		}
	}

	return nextValue;
}

bit Connect::getValue()
{
	return this->state;
}

void Connect::setValue(bit b)
{
	if (b == this->getValue())			//nemohu testovat hned, nutno zjistit, zda nova hodnota neni v rozporu s vystupem nejakého hradla
	{
		return;		//neni zmìna, zahazuju
	}

	//adresuju všechny hradla z propojení a nastavuji jejich odpovídající piny dle b
	//...
	//a nakonec nastavím stav propojení

	this->state = b;

	//LogicsTable *lt = LogicsTable::instance();

	//unsigned int count = this->pins.size();
	unsigned int count = this->nodePins.size();
	unsigned int i;

	for (i = 0; i < count; ++i)
	{
		//string tmp = pins[i];
		//char pin = tmp[tmp.length() - 1];	   //nazevxxxx.A/B cte posledni pismeno
		//string name = tmp.substr(0, tmp.length() - 2);

		NodeItem tmp = this->nodePins[i];

		if (tmp.pin == 'a')			//je vystupní
		{
			//Logic* ll = lt->search(name);

			//if (ll != NULL)
			//{
			//	ll->setA(b);
			//

			tmp.l->setA(b);
		}
		else if (tmp.pin == 'b')
		{
			//Logic* ll = lt->search(name);

			//if (ll != NULL)
			//{
			//	ll->setB(b);
			//}

			tmp.l->setB(b);
		}
		else
		{
			continue;
		}
	}
}

void Connect::setName(string name)
{
	this->name = name;
}

string Connect::getName()
{
	return this->name;
}

void Connect::addToNode(Logic* l, char pin)
{
	NodeItem tmp;

	tmp.l = l;
	tmp.pin = pin;

	this->nodePins.push_back(tmp);
}
