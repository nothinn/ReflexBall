#include <string.h>
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>  
#include "ansi.h"
#include "sin.h"
#include "LED.h"
#include "spil.h"
#include "main.h"
#include "hardware.h"
#define FIX14_SHIFT 14
#define FIX14_MULT(a ,b) ((a)*(b) >> FIX14_SHIFT)
#define FIX14_DIV(a,b) (((a) << FIX14_SHIFT) / (b))
//Lort
<<<<<<< HEAD
=======


>>>>>>> b73b5eae283dbe68e10ee58c0bc35d7a973d72c5

void kollision(struct Ball * ball, struct Striker * striker);


//Test test altså ikke koden!

void runStriker(struct Striker * striker,char push){
	char i;
	push = readkey();
	fgcolor(2);
		
	gotoxy(2+((striker->pos.x-(striker->size/2))>>6),2+(striker->pos.y>>7));
	printf("   %c%c%c%c%c%c%c%c%c%c   ",220,220,220,220,220,220,220,220,220,220);
		
	if(push == 0x01){
		if(striker->pos.x <= 8191){
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
	char frame;

struct Ball ball;
int oldx;
int oldy;
int drawx;
int drawy;
clrscr();
window(2,2,130,66,"Reflexball",1);
ball.pos.x=5000;
ball.pos.y=5000;
ball.speed.x=10;
ball.speed.y=70;
	
	
	striker.pos.x=5000;
	striker.pos.y=7000;
	striker.size=1000;
	push = 0x00;

	
	while(1!=2){			
		if(frame==0){ //beregning
			
			ballupdate(&ball,&drawx,&drawy);
			runStriker(&striker, push);
			kollision(&ball,&striker);
			frame=1;
		}
		else if(frame==1){ 
			if(tid.ms%20==0){ //tegning
			
					if(oldx!=drawx || oldy!=drawy){ //drawBall();
											
					gotoxy(oldx,oldy);
					
					printf("  ");
					gotoxy(drawx,drawy);
					printf("%c%c",219,219);
					oldx=drawx;
					oldy=drawy;	
					
				}	
		 	    frame=2;
			}
		
		
		}else{
			if(tid.ms%20!=0){ //start ny beregning
			frame=0;
			}
		}
	}
		

}

void kollision(struct Ball * ball, struct Striker * striker){
	if( ball->pos.y>7000 && ball->speed.y>0 && ball->pos.x>striker->pos.x-striker->size/2 && ball->pos.x<striker->pos.x+striker->size/2){
				ball->speed.y=-ball->speed.y;
	}

}




void ballupdate(struct Ball * ball,int * drawx, int * drawy){
if(ball->pos.x<0&&ball->speed.x<0 || ball->pos.x>8192&&ball->speed.x>0){
				ball->speed.x=-ball->speed.x;
			}
			if(ball->pos.y<0&&ball->speed.y<0 || ball->pos.y>8192&&ball->speed.y>0){
				ball->speed.y=-ball->speed.y;
			}	
		

			ball->pos.x+=ball->speed.x;
			ball->pos.y+=ball->speed.y;
			*drawx=2+(ball->pos.x>>6);
			*drawy=2+(ball->pos.y>>7);

}