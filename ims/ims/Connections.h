#include <vector>
#include "Connect.h"

using namespace std;

#ifndef __CT_
#define __CT_

class Connections
{
public:
	static Connections* instance();

protected:
	Connections() {};

private:
	Connections(Connections const&);
	Connections& operator=(Connections const&);
	static Connections* pInstance;

public:
	vector<Connect*> cons;		//pro zjednoduseni pristupu

	void add(Connect *);
	Connect *search(string);
	void clearAll();
};

#endif;
