#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include "Parser.h"
#include "BinaryNode.h"
#include "ExpressionTree.h"
#undef main
using namespace std;


bool running = true;
int c = 0;

void update(){

}

void input(){
	SDL_Event event;
	
	while (SDL_PollEvent(&event)){
		switch (event.type){
		case SDL_KEYDOWN:
			break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym){
			case SDLK_ESCAPE:
				running = false;
				break;
			default:
				break;
			}
			break;

		default:
			break;
		}
	} 
}

void render(){
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	
	

	SDL_GL_SwapWindow(wnd);
	SDL_Delay(10);
}

void oglInit(){
	SDL_GL_SetSwapInterval(1);
	glClearColor(0, 0, 0, 1);
}

int main(int argc, char* argv[]){
	SDL_Init(SDL_INIT_EVERYTHING);
	
	SDL_CreateWindowAndRenderer(1600, 800, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN, &wnd, &renderer);
	context = SDL_GL_CreateContext(wnd);
	oglInit();

	while (running){
		input();
		update();
		render();
	}


	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(wnd);
	SDL_Quit();
	return 0;
}