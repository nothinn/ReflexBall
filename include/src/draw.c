#include "ansi.h"
#include "draw.h"
#include <stdio.h>
#include "spil.h"

void drawKlods(struct Klods klods);
void drawBall(struct Ball ball);
void drawStriker(struct Striker striker);
void drawLife(int i);
void drawWindow();
//Lort


void main() {
	struct Klods klods;
	klods.liv = 4;
	klods.pos.x = 4000;
	klods.pos.y = 2000;
	drawKlods(&klods);
}

void drawKlods(struct Klods *klods){
	int i;
	fgcolor = klods.liv;
	reverse("y");
	gotoxy(coordx(klods->pos.x)-4,coordy(klods->pos.y)-1);
	for (i = 0; i < 16; i++){
		putchar(" ")
		if (i = 7){gotoxy(coordx(klods->pos.x)-4,coordy(klods->pos.y));}
	}
	reverse("n");
}

void drawBall(struct Ball *ball){
	struct pos old;

	gotoxy(old.x, old.y);
	putchar(' ');

	gotoxy(coordx(ball->pos.x), coordy(ball->pos.y));
	putchar(219);

	old.x = coordx(ball->pos.x);
	old.y = coordy(ball->pos.y);
}

void drawStriker(struct Striker *striker) {
	static struct pos old;
	char i;

	fgcolor(2);

	gotoxy(old.x - 4, old.y);
	for (i = 0; i < 8; i++) {
		putchar(' ');
	}

	reverse('y');
	gotoxy(coordx(striker->pos.x) - 4, coordy(striker.pos.y));
	for (i = 0; i < 8; i++) {
		putchar(' ');
	}
	reverse('n');

	old.x = coordx(striker->pos.x);
	old.y = coordy(striker->pos.y);
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
	int i, j;
	gotoxy(0, 0);
	for (i = 1; i <= 128; i++) {
		putchar(223);
	}
	for (i = 0; i < 64; i++) {
		down(1);
		left(1);
		putchar(219);
	}
	gotoxy(0, 0);
	for (i = 0; i < 64; i++) {
		down(1);
		left(1);
		putchar(219);
	}
	for (i = 1; i <= 128; i++) {
		putchar(220);
	}

}



void drawMenu(char valg) {

	//PLAY GAME
	gotoxy(60,55);
	printf("______  _                   _____");
	gotoxy(60, 56);
	printf("| ___ \\| |                 |  __ \\");
	gotoxy(60, 57);
	printf("| |_/ /| |  __ _  _   _    | |  \\/  __ _  _ __ ___    ___");
	gotoxy(60, 58);
	printf("|  __/ | | / _` || | | |   | | __  / _` || '_ ` _ \\  / _ \\");
	gotoxy(60, 59);
	printf("| |    | || (_| || |_| |   | |_\\ \\| (_| || | | | | ||  __/");
	gotoxy(60, 60);
	printf("\_|    |_| \__,_| \__, |    \____/ \__,_||_| |_| |_| \___|");
	gotoxy(60, 61);
	printf("                    _/ |");
	gotoxy(60, 62);
	printf("                   |___/");

	//2. PLAYER


}






int coordx(int bigx) {
	return bigx >> 6;
}

int coordy(int bigy) {
	return bigy >> 7;
}