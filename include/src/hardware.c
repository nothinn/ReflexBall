#include <string.h>
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>  
#include "ansi.h"
#include "sin.h"
#include "LED.h"
#include "spil.h"
#include "hardware.h"
#include "main.h"
//Lort


#pragma interrupt
void timer0int(){
DI();

	LEDupdate(0);

	tid.ms++;
//	FLAG=1;
if(tid.ms==1000){tid.ms=0;tid.sec++;}
if(tid.sec==60){tid.min++; tid.sec=0;}
if(tid.min==60){tid.hour++;tid.min=0;}
EI();
}

void hardwaresetup(){
	init_uart(_UART0,_DEFFREQ,BAUD_115200);
	SET_VECTOR(TIMER0, timer0int);
	timer();
	EI();		
	LEDinit();
	LEDupdate(1);
}

void buzz(){
	PDOUT=0x40;
	PDOUT=0x00;
}

void timer(){
	T0CTL=0x19;
	T0H=0x00;
	T0L=0x01;
	T0RH=0x09;
	T0RL=0x00;
	IRQ0ENH =0x20;
	IRQ0ENL =0x20;
	T0CTL=0x99;
	}
	
	
	char readkey(char knap){
	PDDD=0x2F;
	PDADDR=0;
	PFDD=0xC0;
	PFADDR=0;
	
	
	if(knap==0){
		return PDIN&0x07;
	}
	else{
		return (PDIN&0x20)==0x20 ? 1:0;
}

//til controller
//PADD|=0xE0;
//PAADDR=0;
//return (PDIN&0x01 ? 0x04 : 0x00 )|(PDIN&0x04 ? 0x02:0x00)|(PDIN&0x02 ? 0x01 :0x00)|(PDIN&0x08 ? 0x00 :0x04)|(PFIN&0x40 ? 0x00 :0x02)|(PFIN&0x80 ? 0x00 :0x01); 
//return (PDIN&0x08 ? 0x00 :0x04)|(PFIN&0x40 ? 0x00 :0x02)|(PFIN&0x80 ? 0x00 :0x01);
}

