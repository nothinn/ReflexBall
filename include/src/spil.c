#include <sio.h>  
#include <stdlib.h>
#include "ansi.h"
#include "sin.h"
#include "LED.h"
#include "spil.h"
#include "draw.h"
#include "hardware.h"

void spil(int * highscore, char bane){
	int i,j;
	int complete=0;
	struct Striker striker;
	char frame;
	int  score;
	struct Ball ball;
	char ledScore[30] = " Congratz your score was: ";
	int drawx;
	int drawy;
	char livv;
	struct Klods klodser[12][17];
	clrscr();
	LEDupdate(2);
	window(3,4,134,65,"Reflexball",1);
	ball.x=5000;
	ball.y=7000;
	ball.speed.x=0;
	ball.speed.y=0;
	ball.liv=3;	
	striker.pos.x=5000;
	striker.pos.y=7000;
	striker.size=768;

	for(j=0;j<12;j++){
		for(i=0;i<17;i++){
			if(i==0 || i==16 || j==0 ||j==11){
				klodser[j][i].liv=0;
			}else{
				if(bane==2){
					livv=rand() % 4;
				}else{
					livv=0;
					if(i==1 && j<11){livv=3;}
					if(i==2 &&(j<3||j==9 ||j==10)){livv=3;}
					if(i==3 &&(j==2||j==3||j==8||j==9)){livv=3;}
					if(i==4 &&j>2&&j<9){livv=3;}
					if((j==1||j==2) &&i>5&&i<11){livv=3;}
					if(i==8 &&j<11){livv=3;}
					if(i==12 &&j<10){livv=3;}
					if(i==15 &&j<10){livv=3;}
				    if((i==13||i==14) &&(j==10||j==9)){livv=3;}
					if(livv==3){
						if(i+j>9 &&i+j<19){
							livv=2;
						}else if(i+j>18){
							livv=1;
						}
					}
				}
				klodser[j][i].liv= livv;
				klodser[j][i].y=768+j*256;
				klodser[j][i].x=i*(512);
				drawKlods(&klodser[j][i]);
	
				if(	livv==1){
					complete+=5;
				}else if(	livv==2){
					complete+=7;
				}else if(livv==3){
					complete+=8;
				}

			}
		
		}

	}
	drawLife(ball.liv);
	score = 0;

	while(ball.liv>0){ //while loppet som selve spillet kører i
		if(frame<2){ //beregning
			runStriker(&striker, &ball);
			ballupdate(&ball,&drawx,&drawy);
			kollision(&ball,&striker, &klodser[0][0], &score);
			if(complete==score){
				ball.liv=0;
			}
			frame++;
		}else if(frame==2){ 		
			if(tid.ms%40==0){ //tegning
				drawBall(&ball);
	 			drawStriker(&striker);
				pointtoLED(score);
				frame=3;
			}		
		}else{
			if(tid.ms%40!=0){ //start ny beregning
				frame=0;
			}
		}
	}
	//når spillet er færdigt		
	clrscr();
	if(complete!=score){
		drawGO();
	}else{
		drawYouWon();
	}
	updateHS(score, highscore);
	LEDupdate(1);
	ledScore[26]=0x30+score/1000;
	ledScore[27]=0x30+score%1000/100;
	ledScore[28]=0x30+score%100/10;
	ledScore[29]=0x30+score%10;
	ledScore[30]='\0';
	LEDsetString(ledScore);
	while(readkey(1)==1){}
	while(readkey(1)==0){}	
}

void runStriker(struct Striker * striker, struct Ball * ball){
	struct TVector v;
	unsigned char push = readkey(0);

	if(push < 4){
		if(striker->pos.x+striker->size/2 < 8128){
			striker->pos.x += 43*push;	
		}
	}else {
		if(striker->pos.x-striker->size/2 > 64){	
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

void kollision(struct Ball * ball, struct Striker * striker,struct Klods * klodser, int * score){
	int delta;	
	int i,j;
	char a=0;
	int r =striker->size/2;
	int disty,distx;
	struct TVector  v;
	j=(ball->y-384)/256-1;
	i=((ball->x+756)/512-1)+j*17;
	if(j<11 && j>0){	
		if(klodser[i].liv>0 ){
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
			ball->x+=ball->speed.x;
			ball->y+=ball->speed.y;
		}
	}
	if( ball->y>=7000 && ball->y<7000+ball->speed.y && ball->speed.y>0 && ball->x>striker->pos.x-r-64 && ball->x < striker->pos.x+r+64){
		delta=ball->x-striker->pos.x;
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
}

void pointtoLED(int  score){
	char s[4];	
	s[0]=0x30+score/1000;
	s[1]=0x30+score%1000/100;
	s[2]=0x30+score%100/10;
	s[3]=0x30+score%10;
	LEDsetString(s);
}


void ballupdate(struct Ball * ball,int * drawx, int * drawy){
	if((ball->x<128&&ball->speed.x<0) || (ball->x>8064&&ball->speed.x>0)){
		ball->speed.x=-ball->speed.x;			
	}
	if((ball->y<128&&ball->speed.y<0) || (ball->y>8192&&ball->speed.y>0)){
		ball->speed.y=-ball->speed.y;				
	}	
		ball->x+=ball->speed.x;
		ball->y+=ball->speed.y;
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
