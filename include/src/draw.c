#include "ansi.h"
#include "spil.h"
#include "draw.h"
#include <stdio.h>
//#include <stdlib.h>




void drawKlods(struct Klods *klods) {
	int i;
	int tema=1;
	static char k;
	fgcolor (klods->liv+k);
//	reverse('y');
if(klods->x%1024==0 &&klods->y%512==0 || klods->x%1024-512==0 &&klods->y%512!=0){k=8;}else{k=0;}
if(klods->liv==0){
	k=0;
	tema=0;}
	fgcolor (klods->liv+3*tema+k);
	gotoxy(coordx(klods->x-256), coordy(klods->y-128));
	for (i = 0; i < 16; i++) {

		if (i == 8) {
			gotoxy(coordx(klods->x-256), coordy(klods->y-128)+1);
		}
		
putchar(219);
		
	}
//	reverse('n');
}

void drawBall(struct Ball *ball) {
	static struct Pos old;
	reverse('n');
	bgcolor(0);


//	if(oldx!=drawx || oldy!=drawy){ //drawBall();
	fgcolor(15);						
	gotoxy(old.x, old.y);
				
	putchar(' ');
	putchar(' ');
	gotoxy(coordx(ball->x-32), coordy(ball->y));
	putchar(219);
	putchar(219);
	old.x = coordx(ball->x-32);
	old.y = coordy(ball->y);

	gotoxy(200,45);

	//	}




/*

	gotoxy(old.x, old.y);
	putchar(' ');

	gotoxy(coordx(ball->pos.x), coordy(ball->pos.y));
	putchar(219);

	old.x = coordx(ball->pos.x);
	old.y = coordy(ball->pos.y);*/	
}

void drawStriker(struct Striker *striker) {
//	static struct Pos old;
	char i;

	fgcolor(2);
//	gotoxy(((striker.pos.x-(striker.size/2))>>6)+1,5+(striker.pos.y>>7));
//	printf("    %c%c%c%c%c%c%c%c%c%c%c%c    ",220,220,220,220,220,220,220,220,220,220,220,220);
//	gotoxy(old.x - 4, old.y);
//	for (i = 0; i < 8; i++) {
//		putchar(' ');
//	}

	//reverse('y');		go
	gotoxy(coordx(striker->pos.x-(striker->size/2))-4, coordy(striker->pos.y));
	for(i=0;i<22;i++){
		if(i>4 &i<17){
			putchar(220);
		}else{
			putchar(' ');
		}
	}
	fgcolor(1);
	gotoxy(3,59);
	putchar(186);
	gotoxy(134,59);
	putchar(186);
	//	printf("    %c%c%c%c%c%c%c%c%c%c%c%c    ",220,220,220,220,220,220,220,220,220,220,220,220,220,220);
//	for (i = 0; i < 12; i++) {
//		putchar(220);	}
	//reverse('n');

//	old.x = coordx(striker->pos.x);
//	old.y = coordy(striker->pos.y);
}

void drawLife(char i) {
	int j = i;
	fgcolor(1);


	gotoxy(8, 60);//Sletter tidligere hjerter.
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

	gotoxy(8, 60); //Starten af første hjerte.
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
	if (valg == 1) { fgcolor(6); }
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
	if (valg == 2) { fgcolor(6) ; }
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
	if (valg == 3) { fgcolor(6); }
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

void drawGO(){
	gotoxy(20, 30);
	printf("  ________                        ________");
	gotoxy(20, 31);
	printf(" /  _____/_____    _____   ____   \_____  \___  __ ___________");
	gotoxy(20, 32);
	printf("/   \  ___\__  \  /     \_/ __ \   /   |   \  \/ // __ \_  __ \ ");
	gotoxy(20, 33);
	printf("\    \_\  \/ __ \|  Y Y  \  ___/  /    |    \   /\  ___/|  | \/ ");
	gotoxy(20, 34);
	printf(" \______  (____  /__|_|  /\___  > \_______  /\_/  \___  >__|");
	gotoxy(20, 35);
	printf("        \/     \/      \/     \/          \/          \/");
}

int coordx(int bigx) {
	return (bigx >> 6)+5;
}

int coordy(int bigy) {
	return (bigy >> 7)+5;
}
void drawHS(int * highscore){
	char tusi, hund, tier, ener, i, j;

	for(i = 0; i < 5; i++){
		tusi = *highscore/1000;
		hund = (*highscore%1000)/100;
 		tier = (*highscore%100)/10;
		ener = *highscore%10;
		
		gotoxy(22, 20+i*10);
		drawNumber(tusi);
		gotoxy(30, 20+i*10);
		drawNumber(hund);
		gotoxy(38, 20+i*10);
		drawNumber(tier);
		gotoxy(46, 20+i*10);
		drawNumber(ener);

		highscore++;

		

	}
}

void drawNumber(char number){
	if(number == 0){
		printf(" _____ ");
		down(1); left(7);
		printf("|  _  |");
		down(1); left(7);
		printf("| |/' |");
		down(1); left(7);
		printf("|  /| |");
		down(1); left(7);
		printf("\ |_/ /");
		down(1); left(7);
		printf(" \___/ ");
	}else if(number == 1){
		printf("  __   ");
		down(1); left(7);
		printf(" /  |  ");
		down(1); left(7);
		printf(" `| |  ");
		down(1); left(7);
		printf("  | |  ");
		down(1); left(7);
		printf(" _| |_ ");
		down(1); left(7);
		printf(" \___/ ");
	}else if(number == 2){
		printf(" _____ ");
		down(1); left(7);
		printf("/ __  \ ");
		down(1); left(8);
		printf("`' / /'");
		down(1); left(7);
		printf("  / /  ");
		down(1); left(7);
		printf("./ /___");
		down(1); left(7);
		printf("\_____/");
	}else if(number == 3){
		printf(" _____ ");
		down(1); left(7);
		printf("|____ |");
		down(1); left(7);
		printf("    / /");
		down(1); left(7);
		printf("    \ \ ");
		down(1); left(8);
		printf(".___/ /");
		down(1); left(7);
		printf("\____/ ");
	}else if(number == 4){
		printf("   ___ ");
		down(1); left(7);
		printf("  /   |");
		down(1); left(7);
		printf(" / /| |");
		down(1); left(7);
		printf("/ /_| |");
		down(1); left(7);
		printf("\___  |");
		down(1); left(7);
		printf("    |_/");
	}else if(number == 5){
		printf(" _____ ");
		down(1); left(7);
		printf("|  ___|");
		down(1); left(7);
		printf("|___ \ ");
		down(1); left(7);
		printf("    \ \ ");
		down(1); left(8);
		printf("/\__/ /");
		down(1); left(7);
		printf("\____/ ");
	}else if(number == 6){
		printf("  ____ ");
		down(1); left(7);
		printf(" / ___|");
		down(1); left(7);
		printf("/ /___ ");
		down(1); left(7);
		printf("| ___ \ ");
		down(1); left(8);
		printf("| \_/ |");
		down(1); left(7);
		printf("\_____/");
	}else if(number == 7){
		printf(" ______");
		down(1); left(7);
		printf("|___  /");
		down(1); left(7);
		printf("   / / ");
		down(1); left(7);
		printf("  / /  ");
		down(1); left(7);
		printf("./ /   ");
		down(1); left(7);
		printf("\_/    ");
	}else if(number == 8){
		printf(" _____ ");
		down(1); left(7);
		printf("|  _  |");
		down(1); left(7);
		printf(" \ V / ");
		down(1); left(7);
		printf(" / _ \ ");
		down(1); left(7);
		printf("| |_| |");
		down(1); left(7);
		printf("\_____/");
	}else if(number == 9){
		printf(" _____ ");
		down(1); left(7);
		printf("|  _  |");
		down(1); left(7);
		printf("| |_| |");
		down(1); left(7);
		printf("\____ |");
		down(1); left(7);
		printf(".___/ /");
		down(1); left(7);
		printf("\____/ ");
	}
}
