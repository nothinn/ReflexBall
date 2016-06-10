#include "ansi.h"
#include "draw.h"
#include <stdio.h>

void drawKlods(struct Klods klods);
void drawBall(struct Ball ball);
void drawStriker(struct Striker striker);
void drawLife(int i);
void drawWindow();

void drawKlods(struct Klods klods);
void drawBall(struct Ball ball);
void drawStriker(struct Striker striker);
void drawLife(int i);
void drawWindow();

void drawKlods(struct Klods klods){
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

void drawBall(struct Ball ball){
	struct Ball old;

	gotoxy(old.pos.x, old.pos.y);
	printf(" ");

	gotoxy(ball.pos.x, ball.pos.y);
	old.pos.x = ball.pos.x;
	old.pos.y = ball.pos.y;

	printf("*");

}

void drawStriker(struct Striker striker) {
	struct Striker old;
	
}

void drawLife(char i) {
	int j = i;
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

	gotoxy(9, 63); //Starten af første hjerte.
	for (j; j < i; j++) {
		printf("    ");
		down(1);
		left(5);
		printf("    ");
		down(1);
		left(6);
		printf("      ");
		down(1);
		left(5);
		printf("    ");
		down(1);
		left(3);
		printf("  ");
		up(4);
		left(6); // Går til starten af næste hjerte.
	}

}
void drawWindow(){
	
}
