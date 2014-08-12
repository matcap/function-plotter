#include "Parser.h"


Parser::Parser()
{
}


Parser::~Parser()
{
}


int Parser::getClosedBracketPos(string s, int pos){
	int brCount = 1;
	int i = pos + 1;
	while (i < s.size() && brCount > 0){
		if (s[i] == '(')
			brCount++;
		else if (s[i] == ')')
			brCount--;
		i++;
	}
	return i - 1;
}

string Parser::unwrap(string s){
	while (s[0] == '(' && getClosedBracketPos(s, 0) == s.size() - 1)
		s = s.substr(1, s.size() - 2);
	return s;
}

int Parser::getOperator(string expr, int startPos){
	for (int i = 0; i < tokens.size(); i++){
		string cmpstr = expr.substr(startPos, tokens[i].size());
		if (tokens[i].compare(cmpstr) == 0)
			return i;
	}
	return -1;
}

ParseResult* Parser::parse(string expr){
	if (expr.size() == 0)
		return nullptr;

	int lowPriorityToken = tokens.size();	// Track the minimum priority
	int lowPrPos = -1;						// operator token during parsing 
	
	// Remove unwanted chars
	expr = removeChar(expr, ' ');
	expr = unwrap(expr);
	transform(expr.begin(), expr.end(), expr.begin(), tolower);

	// Add 0 to let constants have negative sign
	if (expr[0] == '-')
		expr = '0' + expr;

	for (int i = 0; i < expr.size(); i++){
		char currChar = expr[i];
		
		if (currChar == '('){
			i = getClosedBracketPos(expr, i);
			continue;
		}

		int op = getOperator(expr, i);
		if (op >= 0 && op < lowPriorityToken){
			lowPriorityToken = op;
			lowPrPos = i;
		}
	}

	if (lowPrPos >= 0){
		int opEndPos = lowPrPos + tokens[lowPriorityToken].size();

		ParseResult* result = new ParseResult;
		result->id = static_cast<TokenId>(lowPriorityToken);
		result->lExpr = expr.substr(0, lowPrPos);
		result->rExpr = expr.substr(opEndPos, expr.size() - opEndPos);
		
		return result;
	}
	else if (lowPriorityToken == VARX || lowPriorityToken == VARX)
	{
		ParseResult* result = new ParseResult;
		result->id = static_cast<TokenId>(lowPriorityToken);
		result->lExpr = "";
		result->rExpr = "";

		return result;
	}
	
	ParseResult* result = new ParseResult;
	result->id = CONST;
	result->lExpr = expr;
	result->rExpr = "";

	return result;

}


string Parser::removeChar(string str, char c){
	string newstr;
	for each (char i in str)
		if (i != c)
			newstr += i;
		return newstr;
}