#include <string.h>
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>  
#include "ansi.h"
#include "sin.h"
#include "LED.h"
#include "spil.h"
#include "hardware.h"

#define FIX14_SHIFT 14
#define FIX14_MULT(a ,b) ((a)*(b) >> FIX14_SHIFT)
#define FIX14_DIV(a,b) (((a) << FIX14_SHIFT) / (b))


void timer0int();
void led(char a);

void printFix(long i);
long expand(long i);

//char FLAG;
void initVector(struct TVector * v,long x, long y);
void rotate(struct TVector * v,int angle);

void printchar(char dig);
void menu();
void spil();
void pause();
char TILSTAND;
struct TVector{
long x,y;
};
struct Pos{
int x,y;
};
struct Time{
int hour,min,sec,ms;
};
struct Time tid;
struct Ball{
struct Pos pos;
struct Pos speed;
};
<<<<<<< HEAD
struct Striker{
struct Pos pos;
char size;
};
=======

>>>>>>> refs/remotes/origin/master
struct Klods{
struct Pos pos;
char liv;
char farve;
};





void main(){

	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	SET_VECTOR(TIMER0, timer0int);
	timer();
	EI();
		
	color(2,0);
	printf("%c[?25l",0x1B);
	clrscr();
	window(5,5,60,18,"Stop",1);

	window(7,7,58,16,"Watch",0);
	window(10,10,90,50,"hejsa",1);
	LEDinit();
	LEDsetString("Dette ReflexBall spil bliver mega awesome!<<<<");
	TILSTAND=1;
	while(1!=2){
	switch(TILSTAND){
		case 0 : //menu
		menu();
	   break;
	   case 1:  //spil
	   spil();
	   break;
	   case 2: //pause
		pause();
	   break;
		

	}
	



	}

}
void menu(){
<<<<<<< HEAD
}
void spil(){
char frame;

struct Ball ball;
int oldx;
int oldy;
clrscr();
	window(1,1,102,52,"Reflexball",1);
ball.pos.x=5000;
ball.pos.y=5000;
ball.speed.x=200;
ball.speed.y=300;
=======
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	SET_VECTOR(TIMER0, timer0int);
	timer();
	EI();
		
	color(2,0);
	clrscr();
	window(5,5,60,18,"Stop",1);
	window(7,7,58,16,"Watch",0);
window(10,10,90,50,"hejsa",1);
	LEDinit();
	LEDsetString("Dette ReflexBall spil bliver mega awesome!<<<<");
	TILSTAND=1;
	while(1!=2){
	switch(TILSTAND){
		case 0 : //menu
		menu();
	   break;
	   case 1:  //spil
	   spil();
	   break;
	   case 2: //pause
		pause();
	   break;
		

	}
	
>>>>>>> refs/remotes/origin/master

	while(1!=2){
		if(tid.ms%50==0 && frame==0){
		oldx=ball.pos.x;
		oldy=ball.pos.y;
			ball.pos.x+=ball.speed.x;
			ball.pos.y+=ball.speed.y;
			if(ball.pos.x<0&&ball.speed.x<0 || ball.pos.x>10000&&ball.speed.x>0){
				ball.speed.x=-ball.speed.x;
			}
			if(ball.pos.y<0&&ball.speed.y<0 || ball.pos.y>10000&&ball.speed.y>0){
				ball.speed.y=-ball.speed.y;
			}
		
	if(oldy!=ball.pos.y && oldx!=ball.pos.x){
		gotoxy(oldx/100,oldy/200);
				printf(" ");	
				}
	gotoxy(ball.pos.x/100,ball.pos.y/200);
			printf("%c",219);
			
			frame=1;
		}
		else{
			frame=0;
		}
		
		
	}


	}
}

<<<<<<< HEAD
=======

				
	
	
		
		







	

>>>>>>> refs/remotes/origin/master
void pause(){
}



#pragma interrupt
void timer0int(){
DI();
	LEDupdate();
	tid.ms++;
//	FLAG=1;
if(tid.ms==1000){tid.ms=0;tid.sec++;}
if(tid.sec==60){tid.min++; tid.sec=0;}
if(tid.min==60){tid.hour++;tid.min=0;}
EI();
}

void printchar(char dig){
printf("%c",(dig&0x80 ? '1' :'0'));
printf("%c",(dig&0x40 ? '1' :'0'));
printf("%c",(dig&0x20 ? '1' :'0'));
printf("%c",(dig&0x10 ? '1' :'0'));
printf("%c",(dig&0x08 ? '1' :'0'));
printf("%c",(dig&0x04 ? '1' :'0'));
printf("%c",(dig&0x02 ? '1' :'0'));
printf("%c",(dig&0x01 ? '1' :'0'));
}



void led(char a){
static char clk;
PEDD=0x00;
PEADDR=0;
if(clk==0){ //klokke og colonne
PEOUT=0x8F;
clk=1;
}
else{
PEOUT=0x0F;
clk=0;
}
//data til r�kker
PGDD=0x00;
PGADDR=0;
PGOUT=a&0x7F;


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

void printFix(long i){
//prints 16.16
if((i & 0x80000000) !=0){
printf("-");
i =~i+1;
}
printf("%ld.%04ld", i>>16,10000* (unsigned long) (i & 0xffff) >> 16);
}

long expand(long i){

return i << 2;
}

