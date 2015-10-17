#include "Connect.h"

//state v konstruktoru nastavit na X

bit Connect::getValue()
{
	//stav porpojen� je d�n V�EMI v�stupy hradel (y), kter� jsou k n�mu p�ipojeny
	//v�stupy se mus� jednohlasn� shodnout ve v�stupn�m stavu, jinak je chyba
	//p�ipou�t� se kombinace 0 X -> 0 a 1 X -> 1

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
	this->state = b;
}