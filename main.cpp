#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include "Parser.h"
#include "BinaryNode.h"
#include "ExpressionTree.h"
#include "PlotWindow.h"
#undef main
using namespace std;

int main(int argc, char* argv[]){
	PlotWindow window;
	window.create(1200, 400);
	window.display();

	window.destroy();
	return 0;
}