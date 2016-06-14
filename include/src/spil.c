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

void runStriker(struct Striker * striker,char push, struct Ball * ball){
	char i;
	push = readkey();

		

		
	if(push == 0x01){
		if(striker->pos.x+striker->size/2 < 8064){
			striker->pos.x += 128;
		}
	}else if(push == 0x02){
		if(striker->pos.x-striker->size/2 > 128){	
			striker->pos.x -= 128;
		}
	}
	else if(push == 0x04 && ball->speed.x==0 && ball->speed.y==0){
		ball->speed.y=-127;
	}
				
	
	
		
		

}


void spil(char  * TILSTAND){
	char push, i,j;
 struct Striker striker;
	char frame;

struct Ball ball;

int oldx;
int oldy;
int drawx;
int drawy;
char indexklods;
static char oldindex;
struct Klods klodser[7][17];
clrscr();
window(3,4,134,69,"Reflexball",1);
ball.x;
ball.y;
ball.speed.x=0;
ball.speed.y=0;
ball.liv=3;

	
	
	striker.pos.x=5000;
	striker.pos.y=7000;
	striker.size=768;
	push = 0x00;
for(j=0;j<7;j++){
for(i=0;i<17;i++){
if(i==0 || i==16 || j==0 ||j==6){
	klodser[j][i].liv=0;
}else{
klodser[j][i].liv=3;
}
klodser[j][i].y=768+j*256;
klodser[j][i].x=i*(512);
}
for(i=1;i<16;i++){
drawKlods(&klodser[j][i]);
}
}
drawLife(ball.liv);
	while(ball.liv>0){
	//clrscr();		
		if(frame==0){ //beregning
			
			ballupdate(&ball,&drawx,&drawy);
			runStriker(&striker, push, &ball);
			if(indexklods!=-1){
			oldindex=indexklods;
			}
			indexklods =kollision(&ball,&striker, &klodser[0][0]);			
			frame=1;
		}
		else if(frame==1){ 
			if(tid.ms%40==0){ //tegning
			//clrscr();	
					if(oldx!=drawx || oldy!=drawy){ 
				//	drawBall(&ball);
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
	if(indexklods!=-1){
		drawKlods(&klodser[indexklods/17][indexklods%17]);
		}
			if(indexklods==-1){
		drawBall(&ball);
		}
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
		
	clrscr();
	gotoxy(20,20);
	printf("GAmeover");
	
	while(push == 0x00){
		push = readkey();
	}
	*TILSTAND=0;

		

		
	
}

char kollision(struct Ball * ball, struct Striker * striker,struct Klods * klodser){
int delta;	
char i,j,a;
char out =-1;
int r =striker->size/2;
int vinkel,disty,distx;
//int v;
long x,y;
static struct TVector  v;


j=(ball->y-256)/256-1;

	if(j<6 && j>0){
		for(i=j*17;i<17+j*17;i++){
			
			if(klodser[i].liv>0 && ball->x > klodser[i].x-256 && ball->x<klodser[i].x+256 ){
				LEDsetString("Hallo");
			

			if(ball->speed.y <= 0){
			disty=	(ball->speed.y*-1 / (klodser[i].y+128 - ball->y));
			}else{
			disty=	(ball->speed.y / (ball->y - klodser[i].y - 128 ));
			}

			if(ball->speed.x <= 0){
			distx=	(ball->speed.x*-1 / (klodser[i].x+256 - ball->x));
			}else{
				distx=	(ball->speed.x / (ball->x - klodser[i].x-256));
			}
			if(distx>disty){
					if(ball->speed.x>0){
						a=-1;
					}else{
						a=1;
					}
					if(klodser[i+a].liv>0){
					
						ball->speed.y *= -1;
					}else{
					ball->speed.x *= -1;
					a=0;
					}
					
			}else{
					if(ball->speed.y>0){
						a=-17;
					}else{
						a=17;
					}
					if(klodser[i+a].liv>0){
				
						ball->speed.x *= -1;
					}else{
					ball->speed.y *= -1;
					a=0;
					}
			}
			klodser[i+a].liv--;
			out=i+a;
/*
				if(ball->speed.y <= 0 && ball->speed.x <= 0){
					if((ball->speed.x*-1 / (klodser[i].x+256 - ball->x)) > (ball->speed.y*-1 / (klodser[i].y+128 - ball->y))){
								ball->speed.x *= -1;
					}else{					
						ball->speed.y *= -1;
					}
				}else if(ball->speed.y <= 0 && ball->speed.x >= 0){
					if((ball->speed.x / (ball->x - klodser[i].x-256)) > (ball->speed.y*-1 / (klodser[i].y+128 - ball->y))){
						ball->speed.x *= -1;
					}else{
						ball->speed.y *= -1;
					}
			
				}else if(ball->speed.y >= 0 && ball->speed.x <= 0){
					if((ball->speed.x*-1 / (klodser[i].x+256 - ball->x)) > (ball->speed.y / (ball->y - klodser[i].y - 128 ))){
						ball->speed.x *= -1;
					}else{
						ball->speed.y *= -1;
					}
			
				}else if(ball->speed.y >= 0 && ball->speed.x >= 0){
					if((ball->speed.x / (ball->x - klodser[i].x-256)) > (ball->speed.y / (ball->y - klodser[i].y - 128 ))){
						ball->speed.x *= -1;
					}else{
						ball->speed.y *= -1;
					}
				}
	*/	
				
			
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
	if(ball->y>8000 || (ball->speed.y==0 && ball->speed.x==0)){
		if(ball->y>8000){
			ball->liv--;
			drawLife(ball->liv);
		}
		ball->speed.x=0;
		ball->speed.y=0;
		ball->x=striker->pos.x;
		ball->y=striker->pos.y-128;
		
	
	}


	return out;

}




void ballupdate(struct Ball * ball,int * drawx, int * drawy){
if((ball->x<128&&ball->speed.x<0) || (ball->x>8064&&ball->speed.x>0)){
				//ball->angle=256-ball->angle;
				ball->speed.x=-ball->speed.x;
			}
			if((ball->y<128&&ball->speed.y<0) || (ball->y>8192&&ball->speed.y>0)){
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