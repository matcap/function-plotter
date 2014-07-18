#pragma once
#include "BinaryNode.h"
#include "Parser.h"
#include <string>

typedef BinaryNode* ExpRoot;

class ExpressionTree
{
public:
	ExpressionTree();
	ExpressionTree(string expr);
	virtual ~ExpressionTree();
	void destroy();
	bool create(string expr);
	double eval(Vec2d v);

protected:
	bool recursivelyGen(ExpRoot &root, string expr);
	ExpRoot root;
	string expr;
};

