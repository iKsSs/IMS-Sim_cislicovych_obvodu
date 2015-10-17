#include "Connect.h"
#include "LogicsTable.h"

//state v konstruktoru nastavit na X

bit Connect::getValue()
{	
	//stav porpojení je dán VŠEMI výstupy hradel (y), které jsou k nìmu pøipojeny
	//výstupy se musí jednohlasnì shodnout ve výstupním stavu, jinak je chyba
	//pøipouští se kombinace 0 X -> 0 a 1 X -> 1
	LogicsTable *lt = LogicsTable::instance();
	int count = this->pins.capacity();
	int count2 = lt->logics.capacity();
	int i;
	bit tmpState = X;

	for (i = 0; i < count; ++i)
	{	
		string tmp = pins[i];  
		char pin = tmp[tmp.length() - 1];	   //nazevxxxx.Y cte posledni pismenos
		string name = tmp.substr(0, tmp.length() - 2);

		if (pin == 'Y')			//je vystupní
		{			
			Logic* ll = lt->search(name);

			if (ll != NULL)
			{
				if (ll->getY() == X);
				else if (ll->getY() == L && (tmpState == L || tmpState == X)) tmpState = L;
				else if (ll->getY() == H && (tmpState == H || tmpState == X)) tmpState = H;
				else throw("Chyba v prùbìhu provádìní simulace: konflikt na spojeni.\n");
			}
		}
		else
		{
			continue;
		}
	}

	this->state = tmpState;
	
	return this->state;
}

void Connect::setValue(bit b)
{
	if (b == this->getValue())
	{
		return;		//neni zmìna, zahazuju
	}

	//adresuju všechny hradla z propojení a nastavuji jejich odpovídající piny dle b
	//...
	//a nakonec nastavím stav propojení

	LogicsTable *lt = LogicsTable::instance();
	

	this->state = b;
}

void Connect::setName(string)
{
	this->name = name;
}

string Connect::getName()
{
	return this->name;
}
