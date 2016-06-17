#include <string.h>
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>  
#include <stdlib.h>
#include "ansi.h"
#include "sin.h"
#include "LED.h"
#include "spil.h"
#include "main.h"
#include "menu.h"
#include "draw.h"
#include "hardware.h"

void spil(int * highscore){
	char push;
	int i,j,k;
/*
	char bane[10][17]={
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0},
	{0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0},
	{0,1,1,1,0,0,0,0,1,0,0,1,0,0,0,1,0},
	{0,1,0,1,1,0,0,0,1,0,0,1,0,0,0,1,0},
	{0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0},
	{0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0},
	{0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0},
	{0,1,0,0,1,1,0,0,1,0,0,1,0,0,0,1,0},
	{0,1,0,1,1,0,0,0,1,0,0,1,1,0,1,1,0}};
	char bane2[7][17]={
	{0,1,1,1,0,0,0,0,1,0,0,0,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
	{0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0}};*/

	struct Striker striker;
	char frame;
	int  score;
	struct Ball ball;
	char ledScore[30] = " Congratz your score was: ";
	int oldx;
	int oldy;
	int drawx;
	int drawy;
	int test;
	int indexklods=-1;
	static char oldindex;
	struct Klods klodser[17][17];
	clrscr();
	LEDupdate(2);
	window(3,4,134,65,"Reflexball",1);
	ball.x=0;
	ball.y=0;
	ball.speed.x=0;
	ball.speed.y=0;
	ball.liv=3;	
	striker.pos.x=5000;
	striker.pos.y=7000;
	striker.size=768;
	push = 0x00;
	for(j=0;j<17;j++){
		for(i=0;i<17;i++){
			if(i==0 || i==16 || j==0 ||j>10){
	
				klodser[j][i].liv=0;
			}else{
	/*if(j<10){
		klodser[j][i].liv=bane[j][i];
		}else{
			klodser[j][i].liv=bane2[j-10][i];
		
		}*/
	
				klodser[j][i].liv= rand() % 4;
	/*if(j<10){
		
		klodser[j][i].liv=bane[j][i];
		}else{
	//	klodser[j][i].liv=bane2[j-10][i];
		}*/
	/*
	for(k=17;k<17*17;k++){
	if(k<256){
		klodser[k/17][k%17].liv=bane[k];}
		else{
	klodser[k/17][k%17].liv=bane2[k-255];
		}
	}*/
	
			}
			klodser[j][i].y=768+j*256;
			klodser[j][i].x=i*(512);
		}
	//klodser[5][6].liv=0;
		for(i=1;i<16;i++){
			drawKlods(&klodser[j][i]);
		}
	}
	drawLife(ball.liv);
	score = 0;
	while(ball.liv>0){
		//clrscr();		
		if(frame<2){ //beregning
			runStriker(&striker, push, &ball);
			ballupdate(&ball,&drawx,&drawy);
			indexklods =kollision(&ball,&striker, &klodser[0][0], &score);
			frame++;
		}else if(frame==2){ 
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
			frame=3;
		}
			
			
	}else{
		if(tid.ms%40!=0){ //start ny beregning
			frame=0;
		}
	}
}
			
		clrscr();
		drawGO();
		updateHS(score, highscore);
		LEDupdate(1);
	
		ledScore[26]=0x30+score/1000;
		ledScore[27]=0x30+score%1000/100;
		ledScore[28]=0x30+score%100/10;
		ledScore[29]=0x30+score%10;
		ledScore[30]='\0';
		LEDsetString(ledScore);
	
	while(readkey(1)==1){
		}
	while(readkey(1)==0){
	
		}
	
	
			
	
			
		
}


void runStriker(struct Striker * striker,int push, struct Ball * ball){
	char i;
	struct TVector v;
	push = readkey(0);
	gotoxy(25,25);
		
	if(push < 4){
		if(striker->pos.x+striker->size/2 < 8128){
			striker->pos.x += 43*push;
		}
	}else {
		if(striker->pos.x-striker->size/2 > 128){	
			striker->pos.x -= 43*(push-3);
		}
	}
	if(readkey(1)==1 && ball->speed.x==0 && ball->speed.y==0){
	
		ball->speed.x=16;
		ball->speed.y=-126;
		initVector(&v,0, -127);
		rotate(&v, (rand()%50)-25);
		ball->speed.y=(v.y>>14);
		ball->speed.x=(v.x>>14);
	}
				
	
	
		
		

}


void initVector(struct TVector * v,long x, long y){
	v->x=x<<FIX14_SHIFT;
	v->y=y<<FIX14_SHIFT;
	}
void rotate(struct TVector * v,int angle){
	long x=v->x;
	long y=v->y;
	v->x = FIX14_MULT(x, cos(angle)) - FIX14_MULT(y, sin(angle));
	v->y = FIX14_MULT(x, sin(angle)) + FIX14_MULT(y, cos(angle));
}



int kollision(struct Ball * ball, struct Striker * striker,struct Klods * klodser, int * score){
	int delta;	
	int i,j;
	char a=0;
	char s[4];
	char tal=0;
	int out =-1;
	int r =striker->size/2;
	int vinkel,disty,distx;
	//int v;
	long x,y;
	struct TVector  v;
	
	
	j=(ball->y-384)/256-1;
	
	if(j<16 && j>0){
		for(i=j*17;i<17+j*17;i++){
			
			if(klodser[i].liv>0 && ball->x > klodser[i].x-256 && ball->x<klodser[i].x+256 ){
				tal+=1;
				gotoxy(30,30);
		
			
			
				if(ball->speed.y <= 0){
					disty=	((ball->speed.y*-1)<<8 / (klodser[i].y+128 - ball->y));
				}else{
					disty=	(ball->speed.y<<8 / (ball->y - klodser[i].y - 128 ));
				}

			if(ball->speed.x <= 0){
				distx=	((ball->speed.x*-1)<<8 / (klodser[i].x+256 - ball->x));
			}else{
				distx=	(ball->speed.x<<8 / (ball->x - klodser[i].x-256));
			}
			ball->x-=ball->speed.x;
			ball->y-=ball->speed.y;
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
			drawKlods(&klodser[i+a]);
			if(klodser[i+a].liv==0){
				*score += 5;
			}else if(klodser[i+a].liv==1){
				*score += 2;
 			}else if(klodser[i+a].liv==2){
				*score += 1;
			}
		s[0]=0x30+*score/1000;
		s[1]=0x30+*score%1000/100;
	
		s[2]=0x30+*score%100/10;
		
		s[3]=0x30+*score%10;
		
		LEDsetString(s);
			
		ball->x+=ball->speed.x;
		ball->y+=ball->speed.y;

		out=i+a;
				

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
		buzz(); //vibrere når bolden rammer

	if(ball->speed.y > -32){  	//sikre at man ikke roterer for meget
		ball->speed.y = -32;
		if(ball->speed.x < 0){
			ball->speed.x = -123;
		}else{
			ball->speed.x = 123;
		}
	}		
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
	if(ball->y>7500 || (ball->speed.y==0 && ball->speed.x==0)){
		if(ball->y>7500){
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
void updateHS(int score, int * highscore){
	char i;
	int temp=0;
	
	for(i = 0; i < 5; i++){
    	if(score > *highscore){
		temp=*highscore;
			*highscore = score;
			score=temp;
		}
	   highscore++;
	}
}
