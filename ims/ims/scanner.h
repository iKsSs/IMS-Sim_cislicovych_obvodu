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
	IS		//urèení datového typu
}token;

class Parser
{
public:
	token getToken();

};