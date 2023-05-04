/*
 * BinaryNode.cpp
 *
 *  Created on: 08/giu/2014
 *      Author: Matteo
 */

#include "BinaryNode.h"

/*
 *  BINARY NODE
 *  Generic structure of a BinaryTree node
 */

BinaryNode::BinaryNode() {
	// Set pointers to null
	left = right = NULL;
}

BinaryNode::~BinaryNode() {
	if (left != nullptr) {
		delete left;
		left = nullptr;	
	}

	if (right != nullptr) {
		delete right;
		right = nullptr;
	}
}

double BinaryNode::eval(Vec2d v) {
	return INFINITY;
}





/*
 *   CONSTANT NODE
 *   Leaf of the BinaryTree that returns a constant when evaluated
 */

double ConstantNode::eval(Vec2d v) {
	return val;
}

/*
 *   TokenId NODE
 *   Node that recursively evaluates its children and gives back
 *   the result of a binary arithmetic expression
 */

double OperatorNode::eval(Vec2d v) {
	// Mega switch on all the possible TokenId
	switch (this->op) {

	// Both operands
	case SUM:
		return left->eval(v) + right->eval(v);
	case SUB:
		return left->eval(v) - right->eval(v);
	case DIV:
		return left->eval(v) / right->eval(v);
	case MULT:
		return left->eval(v) * right->eval(v);
	case POW:
		return pow(left->eval(v), right->eval(v));

		// Single operand
	case SIN:
		return sin(right->eval(v));
	case COS:
		return cos(right->eval(v));

	default:
		return 0;
	}
}

/*
 *   VARIABLE NODE
 *	 Leaf that returns the value of a double passed by reference
 */

double VariableNode::eval(Vec2d v){
	switch (var){
	case VARX:
		return v.x;
	case VARY:
		return v.y;
	}
}


