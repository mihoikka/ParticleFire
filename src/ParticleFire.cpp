//============================================================================
// Name        : ParticleFire.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <cstring>
#include <SDL.h>
#include "Screen.h"

using namespace std;

int main(int, char **) { //int WinMain() {

	mrh::Screen screen;
	if(screen.init() == false){
		std::cout << SDL_GetError() << std::endl;
	}
	else{
		while(true){
			if(screen.processEvents() == false){
				screen.close();
				break;
			}
		}
	}

	return 0;
}

