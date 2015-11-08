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
					this->gate_type = attr;
					this->state = ST_GATE;
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

					this->errMsg = "wrong keyword in this content";
					throw(-1);
				}

				break;

			default:
				this->msg = "CHYBA";

				this->errMsg = "keyword not found";
				throw(-1);
				break;
			}
			break;

		case ST_TIME:
			if (this->time != 0)
			{
				this->errMsg = "time redefinition";
				throw(-1);
			}

			this->errMsg = "time value has to be a number";			//in case of exception
			this->time = std::stoi(token->getAttr());
			this->errMsg = "";

			if (this->time < 2)
			{
				this->errMsg = "time too short";
				throw(-1);
			}

			this->msg = "SET TIME: " + std::to_string(this->time);
			this->state = ST_END;
			break;

		case ST_CLK:
			if (this->ct->search("clk") != NULL)
			{
				this->errMsg = "clk redefinition";
				throw(-1);
			}

			//new clk connect
			this->con = new Connect();
			this->con->setName("clk");
			this->ct->add(this->con);

			this->errMsg = "clk value has to be a number";			//in case of exception
			clk = std::stoi(token->getAttr());
			this->errMsg = "";

			clkgen = new CLKgen(clk, this->time, this->con);

			this->msg = "SET CLK: " + token->getAttr();
			this->state = ST_END;
			break;

		case ST_CON:
			if (this->ct->search(token->getAttr()) != NULL)
			{
				this->errMsg = "connection redefinition - " + token->getAttr();
				throw(-1);
			}

			this->con = new Connect();
			this->con->setName(token->getAttr());
			this->ct->add(this->con);

			this->msg = "SET CON: " + token->getAttr();
			this->state = ST_END;
			break;

		case ST_GATE:
			if (this->lt->search(token->getAttr()) != NULL)
			{
				this->errMsg = "gate redefinition - " + token->getAttr();
				throw(-1);
			}

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

				this->errMsg = "comma not found";
				throw(-1);
			}
			break;

		case ST_DELTA:
			this->errMsg = "delay delta has to be a number";			//in case of exception
			this->gate->setDelta(std::stoi(token->getAttr()));
			this->errMsg = "";

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

				this->errMsg = "semicolon not found";
				throw(-1);
			}
			break;

		default:
			this->msg = "DEFAULT - CHYBA";

			this->errMsg = "unspecified";
			throw(-1);
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
					this->msg = "FINISH";

					this->state = ST_FINISH;
				}
				else
				{
					this->msg = "DEF - CHYBA KEYWORD";

					this->errMsg = "wrong keyword in this content";
					throw(-1);
				}

				break;

			case ENDFILE:
				this->msg = "FINISH\n";

				this->state = ST_FINISH;

				break;

			default:
				this->msg = "DEF - CHYBA";

				this->errMsg = "keyword not found";
				throw(-1);
				break;
			}
			break;

		case ST_SET:
			this->schedule = new SchedulerEvent();
			this->schedule->c = this->ct->search(token->getAttr());

			if (this->schedule->c == NULL)
			{
				this->errMsg = "connection not found";
				throw(-1);
			}

			this->msg = "SET: " + token->getAttr();
			this->state = ST_SET_COL;
			break;

		case ST_SET_COL:
			if (token->getAttr() == ",")
			{
				this->state = ST_SET_TIME;
			}
			else
			{
				this->msg = "DEF - SET COL: CHYBA";

				this->errMsg = "comma not found";
				throw(-1);
			}
			break;

		case ST_SET_TIME:
			this->errMsg = "scheduled time has to be a number" + token->getAttr();			//in case of exception
			this->schedule->time = std::stoi(token->getAttr());
			this->errMsg = "";

			this->msg = "TIME: " + token->getAttr();
			this->state = ST_SET_COL2;
			break;

		case ST_SET_COL2:
			if (token->getAttr() == ",")
			{
				this->state = ST_SET_LEVEL;
			}
			else
			{
				this->msg = "DEF - CHYBA";

				this->errMsg = "comma not found";
				throw(-1);
			}
			break;

		case ST_SET_LEVEL:		
			if (token->getAttr() == "L" || token->getAttr() == "0")
			{
				this->schedule->b = L;
			}
			else if (token->getAttr() == "H" || token->getAttr() == "1")
			{
				this->schedule->b = H;
			}
			else if (token->getAttr() == "X")
			{
				this->schedule->b = X;
			}
			else
			{
				this->errMsg = "scheduled level has to be high(H|1) or low(L|0) or X";
				throw(-1);
			}

			this->scheduler->addEvent(this->schedule);

			this->msg = "LEVEL: " + token->getAttr();
			this->state = ST_END;
			break;

		case ST_ADD:
			this->con = ct->search(token->getAttr());

			if (this->con == NULL)
			{
				this->errMsg = "connection not found";
				throw(-1);
			}

			this->msg = "ADD CON: " + token->getAttr();
			this->state = ST_ADD_COL;
			break;

		case ST_ADD_COL:
			if (token->getAttr() == ",")
			{
				this->state = ST_ADD_GATE;
			}
			else
			{
				this->msg = "DEF - CHYBA";

				this->errMsg = "comma not found";
				throw(-1);
			}
			break;

		case ST_ADD_GATE:			
			attr = token->getAttr();
			gate = this->lt->search(attr.substr(0, attr.find('.')));

			if (gate == NULL)
			{
				this->errMsg = "gate not found - " + attr.substr(0, attr.find('.'));
				throw(-1);
			}
			else if (attr.back() == 'a' || attr.back() == 'b' || attr.back() == 'y')
			{
				this->con->addToNode(gate, attr.back());

				this->msg = "ADD GATE: " + attr.substr(0, attr.find('.')) + " PORT: " + attr.back();
				this->state = ST_ADD_END;
			}
			else
			{
				this->errMsg = "wrong gate port - " + attr.back();
				throw(-1);
			}

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

				this->errMsg = "comma or semicolon not found";
				throw(-1);
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

				this->errMsg = "semicolon not found";
				throw(-1);
			}
			break;

		default:
			this->state = ST_NEW;

			this->msg = "DEF - DEFAULT - CHYBA";

			this->errMsg = "unspecified";
			throw(-1);
			break;
		}

	}
}