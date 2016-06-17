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
char liv;
};
struct Klods{
int x,y;
char liv;
};
void initVector(struct TVector * v,long x, long y);
void rotate(struct TVector * v,int angle);

struct TVector{
long x,y;
};

void runStriker(struct Striker * striker,int push, struct Ball * ball);
void ballupdate(struct Ball * ball, int * drawx, int * drawy);
void spil( int * score);


void initVector(struct TVector * v,long x, long y);

void rotate(struct TVector * v,int angle);

int kollision(struct Ball * ball, struct Striker * striker,struct Klods * klodser, int *score);
void updateHS(int score, int * highscore);

#define FIX14_SHIFT 14
#define FIX14_MULT(a ,b) ((a>>14)*(b))
#define FIX14_DIV(a,b) (((a) << FIX14_SHIFT) / (b))

#endif /*! _SPIL_H_ */
//Lort