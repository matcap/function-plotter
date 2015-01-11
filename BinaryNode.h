#include <iostream>
#include <typeinfo>
#include <math.h>
#include <string>
#include "Parser.h"
#ifndef BINARYNODE_H_
#define BINARYNODE_H_

/*
 *  BINARY NODE
 *  Generic structure of a BinaryTree node
 */

class BinaryNode {
public:
	BinaryNode();
	~BinaryNode();
	virtual double eval(Vec2d v);
	BinaryNode* left;
	BinaryNode* right;
};

/*
 *   CONSTANT NODE
 *   Leaf of the BinaryTree that returns a constant when evaluated
 */

class ConstantNode : public BinaryNode{
public:
	ConstantNode(double val) : BinaryNode(){
		this->val = val;
	}
	double eval(Vec2d v);

protected:
	double val;
};

/*
 *   TokenId NODE
 *   Node that recursively evaluates its children and gives back
 *   the result of a binary arithmetic expression
 */

class OperatorNode : public BinaryNode{
public:
	OperatorNode(TokenId op) : BinaryNode(){
		this->op = op;
	}
	double eval(Vec2d v);

protected:
	TokenId op;
};

/*
 *   VARIABLE NODE
 *	 Leaf that returns the value of a double passed by reference
 */

class VariableNode : public BinaryNode{
public:
	VariableNode(TokenId var) : BinaryNode(){
		this->var = var;
	}

	double eval(Vec2d v);

protected:
	TokenId var;
};
#endif /* BINARYNODE_H_ */
