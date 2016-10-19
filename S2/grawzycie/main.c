#include "array.h"
#include "game.h"


void console_goto( int x, int y ){		//funkcja przenoszaca karetke konsoli
	printf("\033[%d;%dH", y+1, x+1);
}

int c=2;		//liczba plikow podanych do main

int main(int c, char **nazwa){
	int row=50,col=50;				//poczatkowe wymiary tablicy
	int nr=1;						//numeracja rund
	cell** world=NULL;
	char* loc_wej=nazwa[1];
	char* loc_wy=nazwa[2];

	world=create(col,row);
	fill_from_file(&world,&col,&row,loc_wej);
	usleep(200000);
	system("clear");

	while(1){
		console_goto(0,0);
		printf("Runda: %d \n",nr);
		generate_round(world,row,col);
		print_array(world,col,row);
		save_to_file(world,col,row,loc_wy);
		usleep(300000);
		nr++;

	}

	delate(&world,row);
	return 0;

}
