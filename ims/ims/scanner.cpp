/*************************************\
*			  *
*	Autoøi:							  *
*		xpitri00 - Martin Pitøík	  *
*		xpastu00 - Jakub Pastuszek	  *
*									  *
\*************************************/
/*
Modul: scanner.cpp
Author: Jakub Pastuszek
Rev: 1
*/

#include "scanner.h"

//definice pripustnych klicovych slov jazyka

char keywords[][C_KEYWORDS] = { "begin", "end", "time", "clk", "and", "or", "not", "nand", "nor", "set", "add" };

//zjisti, zda retezec je klicove slovo

bool Token::isKeyword(std::string str)
{
	int i;
	std::locale loc;

	for (std::string::size_type i = 0; i<str.length(); ++i)
		str[i] = std::tolower(str[i], loc);

	for (i = 0; i < C_KEYWORDS; ++i)
	{
		if (strcmp(str.c_str(), keywords[i]) == 0)
		{
			return true;
		}
	}

	return false;
}

//funkce vraci nacteny token

Token* Token::getTokenData(void)
{
	TState state = ST_INIT;
	std::string str;
	char c;

	Token* token = new Token;

	while (1)
	{
		c = getc(stdin);

		switch (state)
		{
		case ST_INIT:
			if (isspace(c))				//ignorace bilych znaku
			{
				state = ST_INIT;
			}
			else if (c == EOF)			//jsme na konci
			{
				type = ENDFILE;

				return token;
			}
			else if (c == '#')			//zacatek komentare
			{
				state = ST_COMMENT;
			}
			else if (c == ',')
			{
				type = COM;

				return token;
			}
			else if (c == ';')
			{
				type = SEM;

				return token;
			}
			else if (isdigit(c))
			{
				str.push_back(c);

				state = ST_INT;
			}
			else if ((c == '_') || (isalpha(c)))
			{
				str.push_back(c);					//pridani znaku

				state = ST_ID;
			}
			else
			{
				//chyba
			}
			break;

		case ST_COMMENT:
			if (c == '\n')
			{
				state = ST_INIT;
			}
			break;

		case ST_INT:					//zpracovani cisel
			if (isdigit(c))
			{
				//zapisu do retezce
				str.push_back(c);
			}
			else if (c == 'e' || c == 'E')
			{
				//taktez ho zapisi do retezce a nastavim na stav exponentu
				str.push_back(c);
				state = ST_E;
			}
			else if (c == '.')
			{
				//taktez ji zapisi do retezce a nastavim na stav tecky
				str.push_back(c);
				state = ST_DOT;
			}
			else
			{
				//prislo uplne neco jineho, posledni znak zahodim a koncim v INT
				//				fseek(source, -1, SEEK_CUR);

				type = INT;
				//zapisu cislo do atributu
				attr = str;
				str.clear();

				return token;
			}
			break;
		case ST_DOT:
			if (isdigit(c))
			{
				str.push_back(c);
				state = ST_FRACT;
			}
			else
			{
				//chyba
			}
			break;
		case ST_FRACT:
			if (isdigit(c))
			{
				str.push_back(c);
			}
			else if (c == 'e' || c == 'E')
			{
				str.push_back(c);
				state = ST_E;
			}
			else
			{
				//fseek(source, -1, SEEK_CUR);

				type = DOUBLE;

				attr = str;
				str.clear();

				return token;
			}
			break;
		case ST_E:
			if (isdigit(c))
			{
				str.push_back(c);
				state = ST_EXP2;
			}
			else if (c == '+' || c == '-')
			{
				str.push_back(c);
				state = ST_EXP;
			}
			else
			{
				//chyba
			}
			break;
		case ST_EXP:
			if (isdigit(c))
			{
				str.push_back(c);
				state = ST_EXP2;
			}
			else
			{
				//chyba
			}
			break;
		case ST_EXP2:
			if (isdigit(c))
			{
				str.push_back(c);
			}
			else
			{
				//fseek(source, -1, SEEK_CUR);

				type = DOUBLE;

				attr = str;
				str.clear();

				return token;
			}
			break;
			//konec zpracovani cisel

		case ST_ID:
			//je li na vstupu podtrzitko, pismeno nebo cislice, sestavujeme retezec
			if ((c == '_') || (isalpha(c)) || (isdigit(c)))
			{
				str.push_back(c);
			}
			else  //pokud ne, tak nez vratim token, tak se podivam, zda to neni klicove slovo
			{
				//fseek(source, -1, SEEK_CUR);		//vratim posledne nacteny znak

				if (isKeyword(str))
				{
					type = KEYWORD;

					attr = str;
					str.clear();

					return token;
				}
				else
				{
					type = ID;

					attr = str;
					str.clear();

					return token;
				}
			}
			break;
		}
	}
}