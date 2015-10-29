#include <locale>         // std::locale, std::tolower
#include <iostream>
#include <string.h>

/**
* @brief Definice typu tokenu
*/
typedef enum
{
	ID,		//identifikator, nazev daneho hradla
	EQ,		//pøiøazení mzi vývody, pøiøazení konstanty
	L,		//log. 0
	H,		//log. 1
	X,		//log. X
	AND,	//hradlo AND
	OR,		//hrado OR
	NOT,	//hradlo NOT
	NAND,	//hradlo NAND
	NOR,	//hradlo NOR
	IS,		//urèení datového typu
	ENDFILE,
	DOT,
	COM,
	SEM,
	INT,
	DOUBLE,
	KEYWORD
}TTokenType;

/**
* @brief Definice stavu automatu
*/
typedef enum
{
	ST_INIT,
	ST_COMMENT,
	ST_INT,
	ST_DOT,
	ST_FRACT,
	ST_E,
	ST_EXP,
	ST_EXP2,
	ST_ID
}TState;

#ifndef C_KEYWORDS
/**
* @brief Pocet klicovych slov
*/
#define C_KEYWORDS 11
#endif

/**
* @brief Zpracovavany soubor
*/
//FILE *source;

/**
* @brief Definice tokenu
*/
class Token
{
	TTokenType type;
	std::string attr;

	bool isKeyword(std::string str);
public:

	Token* getTokenData();
	void print(){ std::cout << type << ":" << attr << std::endl; }
};

class Parser
{
public:
	Token getToken();

};