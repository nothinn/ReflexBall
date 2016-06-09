#ifndef _ANSI_H_
#define _ANSI_H_
void fgcolor(int foreground);
void bgcolor(int background);
void color(int foreground, int background);
void resetbgcolor();
void clrscr();
void clreol();
void gotoxy(int x, int y);
void underline(char on);
void blink(char on);
void reverse(char on);
void normal();
void window(int x1, int y1, int x2, int y2, char * c,int stil);
void up(int x);

void down(int x);
void right(int x);
void left(int x);
#endif /*! _ANSI_H_ */