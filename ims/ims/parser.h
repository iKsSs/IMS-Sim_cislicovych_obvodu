typedef enum
{
	ID,		//identifikator, nazev daneho hradla
	EQ,		//p�i�azen� mzi v�vody, p�i�azen� konstanty
	L,		//log. 0
	H,		//log. 1
	X,		//log. X
	AND,	//hradlo AND
	OR,		//hrado OR
	NOT,	//hradlo NOT
	NAND,	//hradlo NAND
	NOR,	//hradlo NOR
	IS		//ur�en� datov�ho typu
}token;

class Parser
{
public:
	token getToken();

};