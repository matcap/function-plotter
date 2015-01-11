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
	cin.ignore();
	cin >> input;

	while (input != "exit"){

		if (input.length() > 0){
			ExpressionTree tree;
			cout << "Expanding tree..." << endl;
			tree.create(input);

			cout << "\tStart eval..." << endl;
			PlotData* data = tree.evalRange(Range(-5,5), Range(-5,5), 0.1);

			cout << "\tEval complete"<< endl << "\tDisplaying plot..." << endl;
			
			PlotWindow window;
			if (!window.create(800, 600, "Plot: " + input)){
				SDL_Log("Could not create SDL/OpenGL context");
				break;
			}
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