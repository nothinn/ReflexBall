#include <string.h>
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>  
#include "ansi.h"
#include "sin.h"
#include "LED.h"
#include "spil.h"
#include "main.h"
#include "hardware.h"
#include "menu.h"
#include "draw.h"
#define FIX14_SHIFT 14
#define FIX14_MULT(a ,b) ((a)*(b) >> FIX14_SHIFT)
#define FIX14_DIV(a,b) (((a) << FIX14_SHIFT) / (b))
DrawHS(){}


void menu(char * TILSTAND){
	char push;
	char menuNr = 1;
	char breakmenu = 0;

	drawMenu(menuNr);



	while(breakmenu != 1){
	push = readkey();

		if(push = 0x01){
			while(push == 0x01){}
			if(menuNr <= 2){
			menuNr++;
			}
		}else if(push = 0x02){
			while(push == 0x02){}
			if(menuNr <= 2){
			menuNr--;
			}
		}else if(push = 0x04){
			while(push == 0x04){}
			if(menuNr == 1){
				* TILSTAND = 1;
				breakmenu = 1;
			}else if(menuNr == 2){
				//tilstand = spil2;
				breakmenu = 1;
			}else if(menuNr == 3){
				highScore();
			}
		}
	}
}


void highScore(){
	char push;
	char breakHS = 0;
	DrawHS();

	while(breakHS != 1){
		push = readkey();
		if(push = 0x04){
			while(push == 0x04){}
		breakHS = 1;
		}
	}
}

