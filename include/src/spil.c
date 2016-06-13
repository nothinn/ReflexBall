#include <string.h>
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>  
#include "ansi.h"
#include "sin.h"
#include "LED.h"
#include "spil.h"
#include "main.h"
#include "menu.h"
#include "draw.h"
#include "hardware.h"
#define FIX14_SHIFT 14
#define FIX14_MULT(a ,b) ((a)*(b) >> FIX14_SHIFT)
#define FIX14_DIV(a,b) (((a) << FIX14_SHIFT) / (b))



//void kollision(struct Ball * ball, struct Striker * striker);


//Test test altså ikke koden!

void runStriker(struct Striker * striker,char push){
	char i;
	push = readkey();

		

		
	if(push == 0x01){
		if(striker->pos.x+striker->size/2 < 8129){
			striker->pos.x += 128;
		}
	}else if(push == 0x02){
		if(striker->pos.x-striker->size/2 > 64){	
			striker->pos.x -= 128;
		}
	}
				
	
	
		
		

}


void spil(){
	char push, i;
 struct Striker striker;
	char frame;

struct Ball ball;
int oldx;
int oldy;
int drawx;
int drawy;
struct Klods klodser[20];
clrscr();
window(3,4,134,69,"Reflexball",1);
ball.x=5000;
ball.y=5000;
ball.speed.x=0;
ball.speed.y=150;
ball.angle=74;
	
	
	striker.pos.x=5000;
	striker.pos.y=7000;
	striker.size=768;
	push = 0x00;

for(i=0;i<14;i++){
klodser[i].liv=3;
klodser[i].y=1024;
klodser[i].x=512+i*(512+64);
}
for(i=0;i<14;i++){
drawKlods(&klodser[i]);
}
	
	while(1!=2){
	//clrscr();		
		if(frame==0){ //beregning
			
			ballupdate(&ball,&drawx,&drawy);
			runStriker(&striker, push);
			kollision(&ball,&striker, &klodser[0]);
			frame=1;
		}
		else if(frame==1){ 
			if(tid.ms%40==0){ //tegning
			//clrscr();	
					if(oldx!=drawx || oldy!=drawy){ drawBall(&ball);
				/*		fgcolor(4);						
					gotoxy(oldx,oldy);
					
					printf("   ");
					gotoxy(drawx,drawy);
					printf("%c%c%c",219,219,219);
					oldx=drawx;
					oldy=drawy;	
			drawBall(&ball);
*/
		//	fgcolor(2);			
 drawStriker(&striker);
 
				}	
		 	    frame=2;
			}
		
		
		}else{
			if(tid.ms%40!=0){ //start ny beregning
			frame=0;
			}
		}
	}
		

}

void kollision(struct Ball * ball, struct Striker * striker,struct Klods *klodser){
int delta;	
int i;
int r =striker->size/2;
int vinkel;
//int v;
long x,y;
static struct TVector  v;

if(ball->y>1024-96 && ball->y<1024+96){

for(i=0;i<14;i++){

if(ball->x > klodser[i].x-256 && ball->x<klodser[i].x+256 && klodser[i].liv>0){
klodser[i].liv--;
drawKlods(&klodser[i]);
}

}

}



if( ball->y>=7000 && ball->y<7000+ball->speed.y && ball->speed.y>0 && ball->x>striker->pos.x-r-64 && ball->x < striker->pos.x+r+64){

delta=ball->x-striker->pos.x;

/*	if(delta >0 && delta<r*2*1/5){
		
	
	//ball->speed.y=-ball->speed.y;
		//	ball->speed.x;



//v.x=30<<14;
//v.y=10<<14;
vinkel=-32;
//x=v.x>>14;
//y=v.y>>14;
//gotoxy(5,5);
//printf("%ld:%ld",x,y);	
	
//		ball->speed.y=(hej.x>>14);

		}
		else if( delta<r*2*2/5){
	vinkel=-16;}
	else if(delta<r*2*3/5){
	vinkel=0;
		}
		else if( delta<r*2*4/5){
	vinkel=16;
		}
	 else if(delta<r*2*5/5){
	vinkel=32;
		}*/
		ball->speed.y=-ball->speed.y;
	
		initVector(&v,ball->speed.x, ball->speed.y);
			rotate(&v,delta*32/r);
		ball->speed.y=(v.y>>14);
	ball->speed.x=(v.x>>14);
//	gotoxy(10,10);
//	printf(" %d ",delta*32/r);
//v=cos(ball->speed.y/ball->speed.x);
//gotoxy(5,5);
//printf("%d",v);

	

/*
	if(delta<r/5 && delta>-r/5){
	ball->speed.y=-ball->speed.y;
	}
	else{

initVector(&hej,ball->speed.x, ball->speed.y);
rotate(&hej,200);
	
	ball->speed.y=(hej.y>>12);
	ball->speed.x=hej.x>>12;




	}

*/
	
	
	}

}




void ballupdate(struct Ball * ball,int * drawx, int * drawy){
if(ball->x<64&&ball->speed.x<0 || ball->x>8128&&ball->speed.x>0){
				//ball->angle=256-ball->angle;
				ball->speed.x=-ball->speed.x;
			}
			if(ball->y<0&&ball->speed.y<0 || ball->y>8192&&ball->speed.y>0){
			//ball->angle=256-ball->angle;
				ball->speed.y=-ball->speed.y;
			}	
		

			ball->x+=ball->speed.x;
			ball->y+=ball->speed.y;
		//	ball->pos.x+= FIX14_MULT(500, cos(ball->angle))>>14;
		//	ball->pos.y+= FIX14_MULT(500, sin(ball->angle))>>14;
			*drawx=4+(ball->x>>6);
			*drawy=5+(ball->y>>7);

}