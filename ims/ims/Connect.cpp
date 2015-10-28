#include "Connect.h"
#include "LogicsTable.h"

//state v konstruktoru nastavit na X

Connect::Connect()
{
	this->state = X;
}

vector<bits> Connect::getNextValues()
{
	//LogicsTable *lt = LogicsTable::instance();
	//int count = this->pins.size();
	int count = this->nodePins.size();
	int i;
	vector<bits> nextValue;

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
			bits val;
			//val.time = ll->getDelta();
			val.time = tmp.l->getDelta();
			//val.b = ll->getY();
			val.b = tmp.l->getY();

			//existuje u� z�znam z t�mto �asem?
			int count2 = nextValue.size();
			int j;

			if (count2 == 0)		//vklada prvni prvek
			{
				nextValue.push_back(val);
			}

			for (j = 0; j < count2; ++j)
			{
				if (nextValue[j].time == val.time)		//z�znam existuje, jen kontroluji, zda se hradla, kter� v tento �as vkl�daj�, shodla
				{
					if ((nextValue[j].b == X) || (nextValue[j].b == L && val.b == L) || (nextValue[j].b == H && val.b == H))
					{
						nextValue[j].b = val.b;
					}
					else
					{
						throw("Chyba b�hem simulace, nedefinovan� stav na sb�rnici.\n");
					}
				}
				else //z�znam s t�mto �asem neexistuje
				{
					nextValue.push_back(val);	//tak jej vlo��m
				}
			}
		}
	}

	return nextValue;
}

bit Connect::getValue()
{
	//stav porpojen� je d�n V�EMI v�stupy hradel (y), kter� jsou k n�mu p�ipojeny
	//v�stupy se mus� jednohlasn� shodnout ve v�stupn�m stavu, jinak je chyba
	//p�ipou�t� se kombinace 0 X -> 0 a 1 X -> 1
	/*LogicsTable *lt = LogicsTable::instance();
	int count = this->pins.size();
	int i;
	bit tmpState = X;

	for (i = 0; i < count; ++i)
	{
		string tmp = pins[i];
		char pin = tmp[tmp.length() - 1];	   //nazevxxxx.Y cte posledni pismenos
		string name = tmp.substr(0, tmp.length() - 2);

		if (pin == 'y')			//je vystupn�
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
					throw("Chyba v pr�b�hu prov�d�n� simulace: konflikt na spojeni.\n");
			}
		}
		else
		{
			continue;
		}
	}

	if (tmpState != X)	//hradla se jednozna�n� rozhodla, p�enastav� v�stup
		this->state = tmpState;

	return this->state;*/

	return this->state;
}

void Connect::setValue(bit b)
{
	if (b == this->getValue())			//nemohu testovat hned, nutno zjistit, zda nova hodnota neni v rozporu s vystupem nejak�ho hradla
	{
		return;		//neni zm�na, zahazuju
	}

	//adresuju v�echny hradla z propojen� a nastavuji jejich odpov�daj�c� piny dle b
	//...
	//a nakonec nastav�m stav propojen�

	this->state = b;

	//LogicsTable *lt = LogicsTable::instance();

	//int count = this->pins.size();
	int count = this->nodePins.size();
	int i;

	for (i = 0; i < count; ++i)
	{
		//string tmp = pins[i];
		//char pin = tmp[tmp.length() - 1];	   //nazevxxxx.A/B cte posledni pismeno
		//string name = tmp.substr(0, tmp.length() - 2);

		NodeItem tmp = this->nodePins[i];

		if (tmp.pin == 'a')			//je vystupn�
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

void Connect::addToNode(string el_name_pin)  //co kdyby se tady p�ed�val odkaz na konkr�tn� hradlo - urychlilo by se to, nemuselo by se vyhled�vat
{
	this->pins.push_back(el_name_pin);
}

void Connect::addToNode(Logic* l, char pin)
{
	NodeItem tmp;

	tmp.l = l;
	tmp.pin = pin;

	this->nodePins.push_back(tmp);
}
