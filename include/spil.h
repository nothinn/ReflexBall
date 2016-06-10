#ifndef _SPIL_H_
#define _SPIL_H_
struct Pos{
int x,y;
};
struct Striker{
struct Pos pos;
int size;
};
struct Ball{
struct Pos pos;
struct Pos speed;
};
struct Klods{
struct Pos pos;
char liv;
char farve;
};

void runStriker(struct Striker * striker,char push);
void ballupdate(struct Ball * ball, int * drawx, int * drawy);
void spil();

#endif /*! _SPIL_H_ */
//Lort