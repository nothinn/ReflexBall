#ifndef _HARDWARE_H_
#define _HARDWARE_H_
void hardwaresetup();
void timer();
void timer0int();
void buzz();
char readkey(char knap);
struct Time{
int hour,min,sec,ms;
};
extern struct Time tid;
#endif /*! _HARDWARE_ */
//Lort