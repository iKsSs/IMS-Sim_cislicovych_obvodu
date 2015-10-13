#include "AND.h"
#include "OR.h"

#include <iostream>

using namespace std;

int main(void)
{
	cout << "test" << endl;

	AND and1;
	OR or1;

	and1.setA(true);
	and1.setB(false);
	cout << and1.toString();
	
	system("pause");
}