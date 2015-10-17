#include "Connect.h"
#include "LogicsTable.h"

//state v konstruktoru nastavit na X

bit Connect::getValue()
{	
	//stav porpojen� je d�n V�EMI v�stupy hradel (y), kter� jsou k n�mu p�ipojeny
	//v�stupy se mus� jednohlasn� shodnout ve v�stupn�m stavu, jinak je chyba
	//p�ipou�t� se kombinace 0 X -> 0 a 1 X -> 1
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

		if (pin == 'Y')			//je vystupn�
		{			
			Logic* ll = lt->search(name);

			if (ll != NULL)
			{
				if (ll->getY() == X);
				else if (ll->getY() == L && (tmpState == L || tmpState == X)) tmpState = L;
				else if (ll->getY() == H && (tmpState == H || tmpState == X)) tmpState = H;
				else throw("Chyba v pr�b�hu prov�d�n� simulace: konflikt na spojeni.\n");
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
		return;		//neni zm�na, zahazuju
	}

	//adresuju v�echny hradla z propojen� a nastavuji jejich odpov�daj�c� piny dle b
	//...
	//a nakonec nastav�m stav propojen�

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
