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
	string input;
	cout << "[Plot] >> ";
	getline(cin, input);

	while (input != "exit"){

		if (input.length() > 0){
			ExpressionTree tree;
			tree.create(input);
			debugMSG("TREE CREATED");
			cout << "\tStart eval..." << endl;

			PlotData* data = tree.evalRange({ -10, 10 }, { -10, 10 }, 0.1);
			debugMSG("TREE EVALUATED");
			cout << "\tEval complete"<< endl << "\tDisplaying plot..." << endl;
			
			PlotWindow window;
			window.create(800, 600);
			window.setPlotData(data);
			window.display();
			window.destroy();
		}

		cout << endl << "[Plot] >> ";
		getline(cin, input);
	}

	cout << "Application closed." << endl;
	return 0;
}