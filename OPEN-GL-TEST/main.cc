/*
 * main.cc
 *
 *  Created on: 11 нояб. 2021 г.
 *      Author: Семен Беляев
 */
#include<iostream>
#include<stdexcept>
#include<SDL2/SDL.h>
#include<SDL2/SDL_main.h>
#include "mywindow.h"
#include "housewindow.h"

int main(int, char **){
	SDL_Init(SDL_INIT_EVERYTHING);
	try{
		housewindow w;

		w.main_loop();
	}
	catch (const std::exception &e) {
		std::cerr<< "error" << e.what()<< std::endl;
		exit(1);
	}
	return 0;
}

