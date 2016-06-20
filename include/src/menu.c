#include "ansi.h"
#include "sin.h"
#include "LED.h"
#include "spil.h"
#include "main.h"
#include "hardware.h"
#include "menu.h"
#include "draw.h"

void menu(){
	char push;
	char menuNr = 1;
	char i;
	static int highscore[5];
	color(2,0);
	clrscr();
	for(i = 0; i < 5; i++){
		highscore[i]=0;
	}

	LEDsetString("Play ReflexBall now<<<<<");	
	while(2!= 1){
		drawMenu(menuNr);
		push = readkey(0);
		
		if(push <4 && push>0){
			if(menuNr < 3){
			menuNr++;
			}
		}else if(push >3){
			if(menuNr > 1){
			menuNr--;
			}
		}
	
		if(readkey(1)==1){
			if(menuNr == 1){
				spil(highscore,1);
				while(readkey(0)==1){}
			}else if(menuNr == 2 &&highscore[0]>70){
				spil(highscore,2);
				while(readkey(0)==1){}
			}else if(menuNr == 3){
					drawHS(highscore);
				while(readkey(1)==1){}
				while(readkey(1)==0){}	
			}
			clrscr();
		}
	}
}



