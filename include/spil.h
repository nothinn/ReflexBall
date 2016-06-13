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
int x,y;
struct Pos speed;
long angle;
};
struct Klods{
int x,y;
char liv;
};

void runStriker(struct Striker * striker,char push);
void ballupdate(struct Ball * ball, int * drawx, int * drawy);
void spil();

void kollision(struct Ball * ball, struct Striker * striker,struct Klods * klodser);

#endif /*! _SPIL_H_ */
//Lort