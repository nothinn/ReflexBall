#include "ansi.h"
#include "spil.h"
//#include "draw.h"
#include <stdio.h>
//#include <stdlib.h>




void drawKlods(struct Klods *klods) {
	int i;
	fgcolor (klods->liv);
	reverse('y');
	gotoxy(coordx(klods->pos.x) - 4, coordy(klods->pos.y) - 1);
	for (i = 0; i < 16; i++) {
		putchar(' ');
		if (i == 7) {
			gotoxy(coordx(klods->pos.x) - 4, coordy(klods->pos.y));
		}
	}
	reverse('n');
}

void drawBall(struct Ball *ball) {
	static struct Pos old;

	fgcolor(1);

	gotoxy(old.x, old.y);
	putchar(' ');

	gotoxy(coordx(ball->pos.x), coordy(ball->pos.y));
	putchar(219);

	old.x = coordx(ball->pos.x);
	old.y = coordy(ball->pos.y);
}

void drawStriker(struct Striker *striker) {
	static struct Pos old;
	char i;

	fgcolor(2);

	gotoxy(old.x - 4, old.y);
	for (i = 0; i < 8; i++) {
		putchar(' ');
	}

	//reverse('y');
	gotoxy(coordx(striker->pos.x) - 4, coordy(striker->pos.y));
	for (i = 0; i < 8; i++) {
		putchar(220);
	}
	//reverse('n');

	old.x = coordx(striker->pos.x);
	old.y = coordy(striker->pos.y);
}

void drawLife(char i) {
	int j = i;
	fgcolor(1);


	gotoxy(4, 58);//Sletter tidligere hjerter.
	for (j = 0; j < 5; j++) {
		printf("    ");
		down(1);
		left(5);
		printf("      ");
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
		right(4); // Går til starten af næste hjerte.
	}

	gotoxy(4, 58); //Starten af første hjerte.
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
void drawWindow() {
	int i;
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
	//Drawing font: DOOM, http://patorjk.com/software/taag
	char x = 30;
	char y = 5;

	gotoxy(x, 28);
	fgcolor(1);
	if (valg == 0) { fgcolor(4); }
	//PLAY GAME
	gotoxy(x, y++);
	printf("______  _                   _____");
	gotoxy(x,y++);
	printf("| ___ \\| |                 |  __ \\");
	gotoxy(x, y++);
	printf("| |_/ /| |  __ _  _   _    | |  \\/  __ _  _ __ ___    ___");
	gotoxy(x, y++);
	printf("|  __/ | | / _` || | | |   | | __  / _` || '_ ` _ \\  / _ \\");
	gotoxy(x, y++);
	printf("| |    | || (_| || |_| |   | |_\\ \\| (_| || | | | | ||  __/");
	gotoxy(x, y++);
	printf("\\_|    |_| \\__,_| \\__, |    \\____/ \\__,_||_| |_| |_| \\___|");
	gotoxy(x, y++);
	printf("                    _/ |");
	gotoxy(x, y++);
	printf("                   |___/");

	y += 5;

	fgcolor(1);
	if (valg == 2) { fgcolor(4) ; }
	//2. PLAYER
	gotoxy(x, y++);
	printf(" _____     _____     ______  _");
	gotoxy(x, y++);
	printf("/ __  \\   |  _  |    | ___ \\| |");
	gotoxy(x, y++);
	printf("`' / /'   | |/' |    | |_/ /| |  __ _  _   _   ___  _ __");
	gotoxy(x, y++);
	printf("  / /     |  /| |    |  __/ | | / _` || | | | / _ \\| '__|");
	gotoxy(x, y++);
	printf("./ /___ _ \\ |_/ /    | |    | || (_| || |_| ||  __/| |");
	gotoxy(x, y++);
	printf("\\_____/(_) \\___/     \\_|    |_| \\__,_| \\__, | \\___||_|");
	gotoxy(x, y++);
	printf("                                        __/ |");
	gotoxy(x, y++);
	printf("                                       |___/");


	y += 5;

	fgcolor(1);
	if (valg == 3) { fgcolor(4); }
	//HighScore
	gotoxy(x, y++);
	printf(" _   _  _         _        _____");
	gotoxy(x, y++);
	printf("| | | |(_)       | |      /  ___|");
	gotoxy(x, y++);
	printf("| |_| | _   __ _ | |__    \\ `--.   ___   ___   _ __   ___");
	gotoxy(x, y++);
	printf("|  _  || | / _` || '_ \\    `--. \\ / __| / _ \\ | '__| / _ \\");
	gotoxy(x, y++);
	printf("| | | || || (_| || | | |  /\\__/ /| (__ | (_) || |   |  __/");
	gotoxy(x, y++);
	printf("\\_| |_/|_| \\__, ||_| |_|  \\____/  \\___| \\___/ |_|    \\___|");
	gotoxy(x, y++);
	printf("            __/ |");
	gotoxy(x, y++);
	printf("           |___/");

}



int coordx(int bigx) {
	return bigx >> 6;
}

int coordy(int bigy) {
	return bigy >> 7;
}