#ifndef _MAIN_H_
#define _MAIN_H_

void menu();
void pause();
void timer();
void timer0int();
void printchar(char dig);
char readkey();
void led(char a);
void initVector(struct TVector * v,long x, long y);
void rotate(struct TVector * v,int angle);
void printFix(long i);


void timer0int();
void led(char a);

void printFix(long i);
long expand(long i);

//char FLAG;
void initVector(struct TVector * v,long x, long y);
void rotate(struct TVector * v,int angle);

void printchar(char dig);
void menu();
void spil();
void pause();

struct TVector{
long x,y;
};
struct Time{
int hour,min,sec,ms;
};
extern struct Time tid;










#endif /*! _MAIN_H_ */
//Lort