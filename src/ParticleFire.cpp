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
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include <chrono>
#include <ctime>
using namespace std;

int main(int, char **) { //int WinMain() {

	srand(time(NULL));
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

