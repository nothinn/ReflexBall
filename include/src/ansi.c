#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include <string.h>

#define ESC 0x1B
//Lort
void fgcolor(int foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  int type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

void bgcolor(int background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
 	              way comming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

    Value      Color      
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}

void color(int foreground, int background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  int type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);  
}

void clrscr(){
	printf("%c[2J",ESC);
}

void clreol(){
	printf("%c[K",ESC);
}
void gotoxy(int x, int y){
	printf("%c[%d;%dH",ESC,y,x);
}

void underline(char on){
	if (on == 'y'){
		printf("%c[4m",ESC);
	} else if (on == 'n'){
		printf("%c[24m",ESC);
	}
}

void blink(char on){
	if (on == 'y'){
		printf("%c[5m",ESC);
	} else if (on == 'n'){
		printf("%c[25m",ESC);
	}
}

void reverse(char on){
	if (on == 'y'){
		printf("%c[7m",ESC);
	} else if (on == 'n'){
		printf("%c[27m",ESC);
	}
}
void normal(){
	printf("%c[0;22m",ESC);
}


void window(int x1, int y1, int x2, int y2, char * c,int stil){
	int length = strlen(c);
	int i = 0;
	char kanter[2][9] = {{218,180,195,191,179,192,196,217},{201,185,204,187,186,200,205,188}};

	if (stil != 1){
		stil = 0;
	}


	//color(2,5);
	gotoxy(x1,y1);
	printf("%c%c",kanter[stil][0],kanter[stil][1]);
	reverse('y');
	printf("  %s",c);
	gotoxy(x1+4+length,y1);
	for (i = 0; i < x2 - (x1+5+length);i++){
		printf(" ");
	}
	reverse('n');
	printf("%c%c",kanter[stil][2],kanter[stil][3]);

	for(i = y1+1; i < y2;i++){
		gotoxy(x1,i);
		printf("%c",kanter[stil][4]);
		gotoxy(x2,i);
		printf("%c",kanter[stil][4]);
	}
	
	gotoxy(x1,y2);
	printf("%c",kanter[stil][5]);
	for (i = 0; i < x2-x1-1; i++){
		printf("%c",kanter[stil][6]);
	}
	printf("%c\n",kanter[stil][7]);
	
	normal();
}
void up(int x){
	printf("%c[%dA",ESC,x);
}

void down(int x){
	printf("%c[%dB",ESC,x);
}

void right(int x){
	printf("%c[%dC",ESC,x);
}
void left(int x){
	printf("%c[%dD",ESC,x);
}

