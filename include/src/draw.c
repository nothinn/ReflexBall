#include "ansi.h"
#include "draw.h"
#include <stdio.h>
#include <stdlib.h>



void drawKlods(struct klods){
	int i;
	fgcolor = klods.liv;
	reverse("y");
	gotoxy((klods.pos.x>>6)-4,(klods.pos.y>>7)-1);
	for (i = 0; i < 16; i++){
		printf(" ")
		if (i = 7){gotoxy((klods.pos.x>>6)-4,klods.pos.y>>7);}
	}
	reverse("n");
}

void drawBall(){
	struct Ball
}

void drawStriker(){
	struct Striker
	
}

void drawLife(char i) {
	fgcolor(1);
	gotoxy(9, 63); //Starten af første hjerte.
	for (i; i > 0; i--) {
		printf("_  _");
		down(1);
		left(5);
		printf("/o\\/o\\");
		down(1);
		left(6);
		printf("\\oooo/");
		down(1);
		left(5);
		printf("\\oo/");
		down(1);
		left(3);
		printf("\\/");
		up(4);
		right(4); // Går til starten af næste hjerte.
	}
}
void drawWindow(){
	
}
