#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>  
#include <string.h>
#include "charset.h"
//Lort

static char buffer[5][6];
static char string[100];

void LEDinit(){
	PEDD=0x00;
	PGDD=0x00;
}

void LEDsetString(char * stringin){	
	int i,j,k;
	for(k=0;k<strlen(stringin);k++){
		string[k]=stringin[k];
	}

	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			buffer[i][j]=character_data[string[i]-32][j];
		}
		buffer[i][j]=0x00;	
	}
}

void LEDupdate(){
	static char kolon;
	static char disp;
	static char index;
	static char count;
	static char stal;
	char i,j;
	
		PGOUT=buffer[disp][kolon+index];
		PEOUT=0x1F&(~(0x10>>kolon));
		switch(disp){
			case 0:
			PEOUT|=0x80;break;	
			case 1:
			PGOUT|=0x80;break;
			case 2:
			PEOUT|=0x20;break;
			case 3:
			PEOUT|=0x40;break;
		}
		disp++;
		if(disp==4){
			kolon++;
			disp=0;
		}
		if(kolon==5){
			kolon=0;
		}
		if(count==40){
			index++;
			if(index==6){
				index=0;
				for(i=0;i<4;i++){
					for(j=0;j<5;j++){
						buffer[i][j]=buffer[i+1][j];
						if(i==3){
							buffer[4][j]=character_data[string[5+stal]-32][j];
						}
					}	
				}
				stal++;
	 		    if(stal+6>strlen(string)){
					stal=-5;
				}
			}
			count=0;
		}
		count++;
}


