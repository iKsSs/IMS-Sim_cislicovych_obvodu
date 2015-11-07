#ifndef IMS__PARSER
#define IMS__PARSER

#include <iostream>

#include "LogicsTable.h"
#include "Connections.h"
#include "CLKGen.h"

#include "AND.h"
#include "OR.h"
#include "NOR.h"
#include "NOT.h"
#include "NAND.h"

#include "scanner.h"

/**
* @brief Definice stavu automatu
*/
typedef enum
{
	ST_NEW,
	ST_TIME,
	ST_CLK,
	ST_GATE,
	ST_GATE_COL,
	ST_DELTA,
	ST_SET,
	ST_SET_COL,
	ST_SET_TIME,
	ST_SET_COL2,
	ST_SET_LEVEL,
	ST_CON,
	ST_ADD,
	ST_ADD_COL,
	ST_ADD_GATE,
	ST_ADD_END,
	ST_END,
	ST_FINISH
}PState;

class Parser
{
	int time;

	LogicsTable *lt;
	Connections *ct;
	Scheduler *scheduler;

	PState state;
	bool definition;

	std::string gate_type;
	Logic *gate;
	SchedulerEvent *schedule;
	Connect *con;

	std::string msg;

public:
	Parser() : time{ 0 }, state{ ST_NEW }, definition{ false } {
		lt = LogicsTable::instance();
		ct = Connections::instance();
		scheduler = Scheduler::instance();
	}
	void processToken(Token *token);
	int getTime() { return this->time; }
	void print() { if ( !msg.empty() ) std::cout << this->msg << std::endl; }
};

#endif
