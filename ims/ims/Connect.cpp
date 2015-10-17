#include "Connect.h"

//state v konstruktoru nastavit na X

bit Connect::getValue()
{
	//stav porpojení je dán VŠEMI vıstupy hradel (y), které jsou k nìmu pøipojeny
	//vıstupy se musí jednohlasnì shodnout ve vıstupním stavu, jinak je chyba
	//pøipouští se kombinace 0 X -> 0 a 1 X -> 1

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
	this->state = b;
}