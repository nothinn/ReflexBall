void runStriker(struct Striker * striker,char push){
	char i;
	push = readkey();
	fgcolor(2);
		
	gotoxy((striker->pos.x-(striker->size/2))/100,striker->pos.y/200);
	printf("   %c%c%c%c%c%c%c%c%c%c   ",220,220,220,220,220,220,220,220,220,220);
		
	if(push == 0x01){
		if(striker->pos.x <= 10000){
			striker->pos.x += 50;
		}
	}else if(push == 0x02){
		if(striker->pos.x >= 1){	
			striker->pos.x -= 50;
		}
	}
				
	
	
		
		

}


void spil(){
	char push, i;
	static struct Ball ball;
	static struct Striker striker;
	ball.pos.x=5000;
	ball.pos.y=5000;
	ball.speed.x=100;
	ball.speed.y=200;
	striker.pos.x=5000;
	striker.pos.y=10000;
	striker.size=10;
	push = 0x00;

	while(1!=2){
		runStriker(&striker, push);
	}
	
		

}