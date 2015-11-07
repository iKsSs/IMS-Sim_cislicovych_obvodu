
#ifndef IMS__SCANNER
#define IMS__SCANNER

#include <locale>         // std::locale, std::tolower
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

/**
* @brief Definice typu tokenu
*/
typedef enum
{
	ID,		//identifikator, nazev daneho hradla
	ENDFILE,
	COM,
	SEM,
	INT,
	DOUBLE,
	KEYWORD,
	ERR
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
#define C_KEYWORDS 12
#endif

/**
* @brief Definice tokenu
*/
class Token
{
	TTokenType type;
	std::string attr;

	std::ifstream file;

	bool isKeyword(std::string str);
public:
	Token() {}
	Token(std::string file);
	~Token();

	Token* getTokenData();
	void print() { std::cout << "\t\t\t" << type << ":\t" << attr << std::endl; }
	TTokenType getType() { return this->type; }
	std::string getAttr() { return this->attr; }
};


#endif