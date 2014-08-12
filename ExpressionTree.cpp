#include "ExpressionTree.h"

ExpressionTree::ExpressionTree()
{
}

ExpressionTree::ExpressionTree(string expr)
{
	create(expr);
}


ExpressionTree::~ExpressionTree()
{
	destroy();
}

bool ExpressionTree::create(string expr){
	this->expr = expr;
	destroy();
	return recursivelyGen(root, expr);
}

void ExpressionTree::destroy(){
	delete root;
}

double ExpressionTree::eval(Vec2d v){
	if (root != nullptr)
		return root->eval(v);
	else
		return 0;
}

bool ExpressionTree::recursivelyGen(ExpRoot &root, string expr){
	Parser parser;
	ParseResult* res = parser.parse(expr);

	if (res == nullptr)
		return false;

	if (res->id < tokens.size()){
		if (res->id == VARX || res->id == VARY){
			root = new VariableNode(res->id);
			return true;
		}

		root = new OperatorNode(res->id);
		return recursivelyGen(root->left, res->lExpr) &	recursivelyGen(root->right, res->rExpr);
	}

	else {
		double d = strtod(expr.c_str(), nullptr);
		root = new ConstantNode(d);
		return true;
	}
	return false;
}

	PlotData* ExpressionTree::evalRange(Range xrange, Range yrange, float step)
	{
		PlotData* data = new PlotData();
		data->cols = data->rows = 0;
		for (float x = xrange.low; x <= xrange.high; x += step){
			for (float y = yrange.low; y <= yrange.high; y += step){
				float z = (float) this->eval({ x, y });
				data->points.push_back(Vector3f(x, y, z));
				data->cols++;
			}
			data->rows++;
		}
		data->cols /= data->rows;
		return data;
	}