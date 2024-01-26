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
		/*auto start = std::chrono::system_clock::now();*/

		while (true){
			if(screen.processEvents() == false){
				screen.close();
				break;
			}
		}
		// Some computation here
		/*auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> elapsed_seconds = end-start;
		std::time_t end_time = std::chrono::system_clock::to_time_t(end);

		std::cout << "finished computation at " << std::ctime(&end_time)
				  << "elapsed time: " << elapsed_seconds.count() << "s"
				  << std::endl;*/
	}

	return 0;
}

