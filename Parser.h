#pragma once
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include "globals.h"
using namespace std;

typedef struct {
	TokenId id;
	string lExpr;
	string rExpr;
} ParseResult;

static const vector<string> tokens = {
	"+",
	"-",
	"*",
	"/",
	"^",
	"sin",
	"cos",
	"tan",
	"atan",
	"sqrt",
	"x",
	"y"
};

class Parser
{
public:
	Parser();
	virtual ~Parser();
	ParseResult* parse(string expr);
private:
	int getClosedBracketPos(string s, int pos);
	string unwrap(string s);
	int getOperator(string expr, int startPos); //-1 if not an operator, else TokenId
	string removeChar(string str, char c);
};

