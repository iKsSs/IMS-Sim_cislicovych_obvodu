#include <vector>
#include <string>

#include "Logic.h"

using namespace std;

#ifndef __CONNECT_
#define __CONNECT_

typedef struct
{
	unsigned int time;		//kdy
	bit b;					//na jakou hodnotu
	//int i;				//koho aktualozovat (index do connections)
	void *c;				//koho aktualizovat (void ukazatel je zde pou��t, proto�e je�t� nen� zn�ma t��da connect, nicm�n� t��da connect tuto strukturu vyu��v� a proto mus� b�t uvedena p�ed n�
} bits;

typedef struct
{
	Logic *l;
	char pin;
} NodeItem;

class Connect
{
private:
	bit state;
	vector<string> pins;  //ZASTARALE!!! jmena hradel s teckovou notaci portu, dane hradlo se pot� nalezne v tabulce hradel (vektor)
	vector<NodeItem> nodePins;
	string name;
public:
	Connect();
	void setValue(bit);
	bit getValue();  //return state
	vector<bits*> getNextValues(); //vrac� hodnoty sb�rnice v n�sleduj�c�h �asech, jak se vyvolaj� ud�losti na hradlech, po uplynut� zpo�d�n�
	void setName(string);
	string getName();
	void addToNode(string);		//zastaral�, ponech�no jen kv�li rozhran� zat�m neaktualizovan�ch funkc�!!!
	void addToNode(Logic*, char);
};

#endif
