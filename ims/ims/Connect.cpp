#include "Connect.h"
#include "LogicsTable.h"

//state v konstruktoru nastavit na X

Connect::Connect()
{
	this->state = X;
}

bit Connect::getValue()
{	
	//stav porpojení je dán VŠEMI výstupy hradel (y), které jsou k nìmu pøipojeny
	//výstupy se musí jednohlasnì shodnout ve výstupním stavu, jinak je chyba
	//pøipouští se kombinace 0 X -> 0 a 1 X -> 1
	LogicsTable *lt = LogicsTable::instance();
	int count = this->pins.size();
	int i;
	bit tmpState = X;

	for (i = 0; i < count; ++i)
	{	
		string tmp = pins[i];  
		char pin = tmp[tmp.length() - 1];	   //nazevxxxx.Y cte posledni pismenos
		string name = tmp.substr(0, tmp.length() - 2);

		if (pin == 'y')			//je vystupní
		{			
			Logic* ll = lt->search(name);

			if (ll != NULL)
			{
				if (ll->getY() == X);
				else if (ll->getY() == L && (tmpState == L || tmpState == X)) 
					tmpState = L;
				else if (ll->getY() == H && (tmpState == H || tmpState == X)) 
					tmpState = H;
				else 
					throw("Chyba v prùbìhu provádìní simulace: konflikt na spojeni.\n");
			}
		}
		else
		{
			continue;
		}
	}

	if (tmpState != X)	//hradla se jednoznaènì rozhodla, pøenastaví výstup
		this->state = tmpState;
	
	return this->state;
}

void Connect::setValue(bit b)
{
	//if (b == this->getValue())			//nemohu testovat hned, nutno zjistit, zda nova hodnota neni v rozporu s vystupem nejakého hradla
	//{
	//	return;		//neni zmìna, zahazuju
	//}

	//adresuju všechny hradla z propojení a nastavuji jejich odpovídající piny dle b
	//...
	//a nakonec nastavím stav propojení

	this->state = b;

	LogicsTable *lt = LogicsTable::instance();
	
	int count = this->pins.size();
	int i;

	for (i = 0; i < count; ++i)
	{
		string tmp = pins[i];
		char pin = tmp[tmp.length() - 1];	   //nazevxxxx.A/B cte posledni pismeno
		string name = tmp.substr(0, tmp.length() - 2);

		if (pin == 'a')			//je vystupní
		{
			Logic* ll = lt->search(name);

			if (ll != NULL)
			{
				ll->setA(b);
			}
		}
		else if (pin == 'b')
		{
			Logic* ll = lt->search(name);

			if (ll != NULL)
			{
				ll->setB(b);
			}
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

void Connect::addToNode(string el_name_pin)
{
	this->pins.push_back(el_name_pin);
}
