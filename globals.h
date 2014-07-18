
enum TokenId{
	// Binary operators
	SUM,
	SUB,
	MULT,
	DIV,
	POW,
	// Unary operators
	SIN,
	COS,
	// Variables
	VARX,
	VARY,
	// Constants
	CONST
};


typedef struct{
	double x;
	double y;
} Vec2d;