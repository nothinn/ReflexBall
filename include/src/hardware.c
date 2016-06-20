
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>  
#include "LED.h"
#include "hardware.h"

#pragma interrupt
void timer0int(){
	DI();
	LEDupdate(0);
	tid.ms++;
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
	char in =0x00;
	PDDD=0x2F;
	PDADDR=0;
	PFDD=0xC0;
	PFADDR=0;
	
	if(knap==0){	//controller styring start	
		return (PDIN&0x07);
	}
	else{	
		return (PDIN&0x20)==0x20 ? 1:0;
	}
 //controller stryring slut

 //styring på boardet start	
/*	if(knap==0){
		if((PFIN&0x40)!=0x40){ 
			in = 0x06;
		}else if((PFIN&0x80)!=0x80){
			in =0x03;		
		}
		return in;
	}
	else if((PDIN&0x08)!=0x08){		
		return 1;
	}else{
		return 0;
	}*/
	//styring på boardet slut
}

