#include <string>
#include <vector>

#include "Logic.h"
#include "Connections.h"
#include "LogicsTable.h"

using namespace std;

typedef enum
{
	SLO,
	KLO
}SIM_TYPE;

class SimCore
{
private:
	int resolution;
	int time;
	int elapsedTime;
	LogicsTable *logicTable;
	Connections *connections;

	void init();
public:
	SimCore(SIM_TYPE, int, int);		//odkazy od tabulek si veme
	void run();							//spuštìní simulace
};