#include <string.h>
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>  
#include "ansi.h"
#include "sin.h"
#include "LED.h"
#include "spil.h"
#include "main.h"
#define FIX14_SHIFT 14
#define FIX14_MULT(a ,b) ((a)*(b) >> FIX14_SHIFT)
#define FIX14_DIV(a,b) (((a) << FIX14_SHIFT) / (b))
//Lort
struct Pos{
int x,y;
};
struct Striker{
struct Pos pos;
int size;
};


//Test test altså ikke koden!

void runStriker(struct Striker * striker,char push){
	char i;
	push = readkey();
	fgcolor(2);
		
	gotoxy((striker->pos.x-(striker->size/2))/100,striker->pos.y/200);
	printf("   %c%c%c%c%c%c%c%c%c%c   ",220,220,220,220,220,220,220,220,220,220);
		
	if(push == 0x01){
		if(striker->pos.x <= 10000){
			striker->pos.x += 50;
		}
	}else if(push == 0x02){
		if(striker->pos.x >= 1){	
			striker->pos.x -= 50;
		}
	}
				
	
	
		
		

}


void spil(){
	char push, i;
	static struct Striker striker;
	striker.pos.x=5000;
	striker.pos.y=10000;
	striker.size=10;
	push = 0x00;

	while(1!=2){
		runStriker(&striker, push);
	}
	
		

}