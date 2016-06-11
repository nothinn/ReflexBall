#ifndef _DRAW_H_
#define _DRAW_H_


void drawKlods(struct Klods *klods);
void drawBall(struct Ball *ball);
void drawStriker(struct Striker *striker);
void drawLife(char i);
void drawWindow();
void drawMenu(char valg);
int coordx(int bigx);
int coordy(int bigy);

#endif