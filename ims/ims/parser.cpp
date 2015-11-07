#include "parser.h"

void Parser::processToken(Token *token)
{
	std::string attr;
	int clk;
	CLKgen *clkgen;	

//	std::cout << this->state << std::endl;

	this->msg = "";

	if (!definition)
	{
		switch (this->state)
		{
		case ST_NEW:
			switch (token->getType())
			{
			case KEYWORD:
				attr = token->getAttr();
				if (attr == "time")
				{
					this->state = ST_TIME;
				}
				else if (attr == "clk")
				{
					this->state = ST_CLK;
				}
				else if (attr == "and" || attr == "nand" || attr == "or" || attr == "nor" || attr == "not")
				{
					this->state = ST_GATE;
					this->gate_type = attr;
				}
				else if (attr == "con")
				{
					this->state = ST_CON;
				}
				else if (attr == "begin")
				{
					this->definition = true;
					this->msg = "\nSTART DEFINITION:\n";
					this->state = ST_NEW;
				}
				else
				{
					this->msg = "CHYBA KEYWORD";
				}

				break;

			default:
				this->msg = "CHYBA";
				break;
			}
			break;

		case ST_TIME:
			this->time = std::stoi(token->getAttr());
			this->msg = "SET TIME: " + std::to_string(this->time);
			this->state = ST_END;
			break;

		case ST_CLK:
			this->con = new Connect();
			this->con->setName("clk");
			this->ct->add(this->con);
			clk = std::stoi(token->getAttr());
			clkgen = new CLKgen(clk, this->time, this->con);
			this->msg = "SET CLK: " + token->getAttr();
			this->state = ST_END;
			break;

		case ST_CON:
			this->con = new Connect();
			this->con->setName(token->getAttr());
			this->ct->add(this->con);
			this->msg = "SET CON: " + token->getAttr();
			this->state = ST_END;
			break;

		case ST_GATE:
			if (this->gate_type == "nand")
			{
				this->gate = new NAND();
				this->msg = "SET NAND: " + token->getAttr();
			}
			else if (this->gate_type == "and")
			{
				this->gate = new AND();
				this->msg = "SET AND: " + token->getAttr();
			}
			else if (this->gate_type == "or")
			{
				this->gate = new OR();
				this->msg = "SET OR: " + token->getAttr();
			}
			else if (this->gate_type == "nor")
			{
				this->gate = new NOR();
				this->msg = "SET NOR: " + token->getAttr();
			}
			else if (this->gate_type == "not")
			{
				this->gate = new NOT();
				this->msg = "SET NOT: " + token->getAttr();
			}
			else
			{
				this->msg = "NOT SET: CHYBA";
			}

			this->gate->setName(token->getAttr());

			this->state = ST_GATE_COL;
			break;

		case ST_GATE_COL:
			if (token->getAttr() == ",")
			{
				this->state = ST_DELTA;
			}
			else
			{
				this->msg = "SET COL: CHYBA";
			}
			break;

		case ST_DELTA:
			this->gate->setDelta(std::stoi(token->getAttr()));
			this->lt->add(this->gate);
			this->msg = "SET DELTA: " + token->getAttr();
			this->state = ST_END;
			break;

		case ST_END:
			if (token->getAttr() == ";")
			{
				this->state = ST_NEW;
			}
			else
			{
				this->msg = "CHYBA";
			}
			break;

		default:
			this->state = ST_NEW;
			this->msg = "DEFAULT - CHYBA";
			break;
		}
	}
	else
	{
		switch (this->state)
		{
		case ST_NEW:
			switch (token->getType())
			{
			case KEYWORD:
				attr = token->getAttr();
				if (attr == "set")
				{
					this->state = ST_SET;
				}
				else if (attr == "add")
				{
					this->state = ST_ADD;
				}
				else if (attr == "end")
				{
					this->state = ST_FINISH;
					this->msg = "FINISH";
				}
				else
				{
					this->msg = "DEF - CHYBA KEYWORD";
				}

				break;

			case ENDFILE:
				this->state = ST_FINISH;
				this->msg = "FINISH\n";
				break;

			default:
				this->msg = "DEF - CHYBA";
				break;
			}
			break;

		case ST_SET:
			this->state = ST_SET_COL;
			this->schedule = new SchedulerEvent();
			this->schedule->c = ct->search(token->getAttr());
			this->msg = "SET: " + token->getAttr();
			break;

		case ST_SET_COL:
			this->state = ST_SET_TIME;
			break;

		case ST_SET_TIME:
			this->state = ST_SET_COL2;
			this->schedule->time = std::stoi(token->getAttr());
			this->msg = "TIME: " + token->getAttr();
			break;

		case ST_SET_COL2:
			this->state = ST_SET_LEVEL;
			break;

		case ST_SET_LEVEL:
			this->state = ST_END;
			if (token->getAttr() == "L" || token->getAttr() == "0")
			{
				this->schedule->b = L;
			}
			else
			{
				this->schedule->b = H;
			}
			this->scheduler->addEvent(this->schedule);
			this->msg = "LEVEL: " + token->getAttr();
			break;

		case ST_ADD:
			this->state = ST_ADD_COL;
			this->con = ct->search(token->getAttr());
			this->msg = "ADD CON: " + token->getAttr();
			break;

		case ST_ADD_COL:
			this->state = ST_ADD_GATE;
			break;

		case ST_ADD_GATE:
			this->state = ST_ADD_END;
			attr = token->getAttr();
			gate = this->lt->search(attr.substr(0, attr.find('.')));
			this->con->addToNode(gate, attr.back());
			this->msg = "ADD GATE: " + attr.substr(0, attr.find('.')) + " PORT: " + attr.back();
			break;

		case ST_ADD_END:
			if (token->getAttr() == ";")
			{
				this->state = ST_NEW;
			}
			else if (token->getAttr() == ",")
			{
				this->state = ST_ADD_GATE;
			}
			else
			{
				this->msg = "DEF - CHYBA";
			}
			break;

		case ST_FINISH:
			break;

		case ST_END:
			if (token->getAttr() == ";")
			{
				this->state = ST_NEW;
			}
			else
			{
				this->msg = "DEF - CHYBA";
			}
			break;

		default:
			this->state = ST_NEW;
			this->msg = "DEF - DEFAULT - CHYBA";
			break;
		}

	}
}