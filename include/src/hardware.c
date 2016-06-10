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
#define FIX14_SHIFT 14
#define FIX14_MULT(a ,b) ((a)*(b) >> FIX14_SHIFT)
#define FIX14_DIV(a,b) (((a) << FIX14_SHIFT) / (b))

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


char readkey(){
PDDD=0x08;
PDADDR=0;
PFDD=0xC0;
PFADDR=0;
return (PDIN&0x08 ? 0x00 :0x04)|(PFIN&0x40 ? 0x00 :0x02)|(PFIN&0x80 ? 0x00 :0x01);
}

