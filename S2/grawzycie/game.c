#include "game.h"

void generate_round(cell** world,int wiersze, int kolumny){

	clear_mate(world,kolumny,wiersze);
	caculate_mate(world,kolumny,wiersze);
	born(world,kolumny,wiersze);

}

void caculate_mate(cell** world,int kolumny,int wiersze){
	int k,w;

//******sprawdzanie rogów tablicy*****************************
//******przyjmuje ze poza wymiarami tablicy sa tylko martwi***

	world[0][0].mate =world[0][1].alive
					+world[1][0].alive
					+world[1][1].alive;

	world[0][kolumny-1].mate =world[0][kolumny-2].alive
							+world[1][kolumny-1].alive
							+world[1][kolumny-2].alive;

	world[0][kolumny-1].mate =world[0][kolumny-2].alive
							+world[1][kolumny-1].alive
							+world[1][kolumny-2].alive;

	world[wiersze-1][0].mate =world[wiersze-2][0].alive
							+world[wiersze-1][1].alive
							+world[wiersze-2][1].alive;

	world[wiersze-1][kolumny-1].mate =world[wiersze-2][kolumny-1].alive
									+world[wiersze-1][kolumny-2].alive
									+world[wiersze-2][kolumny-2].alive;

//******sprawdzanie zewnetrznych krwedzi******************

	for(w=1 ; w<wiersze-1 ; w++){
		world[w][0].mate =world[w-1][0].alive
						+world[w+1][0].alive
						+world[w-1][1].alive
						+world[w][1].alive
						+world[w+1][1].alive;
	}

	for(w=1 ; w<wiersze-1 ; w++){
		world[w][kolumny-1].mate =world[w-1][kolumny-1].alive
								+world[w+1][kolumny-1].alive
								+world[w-1][kolumny-2].alive
								+world[w][kolumny-2].alive
								+world[w+1][kolumny].alive;
	}

	for(k=1 ; k<kolumny-1 ; k++){
		world[0][k].mate =world[0][k-1].alive
						+world[0][k+1].alive
						+world[1][k-1].alive
						+world[1][k].alive
						+world[1][k+1].alive;
	}

	for(k=1 ; k<kolumny-1 ; k++){
		world[wiersze-1][k].mate =world[wiersze-1][k-1].alive
								+world[wiersze-1][k+1].alive
								+world[wiersze-2][k-1].alive
								+world[wiersze-2][k].alive
								+world[wiersze-2][k+1].alive;
	}

//*****sprawdznie wnetrza planszy*****************

	for(w=1 ; w<wiersze-1 ; w++){
		for(k=1 ; k<kolumny-1 ; k++){

			world[w][k].mate =world[w-1][k-1].alive
								+world[w-1][k].alive
								+world[w-1][k+1].alive
								+world[w][k-1].alive
								+world[w][k+1].alive
								+world[w+1][k-1].alive
								+world[w+1][k].alive
								+world[w+1][k+1].alive;
		}
	}
}

void born(cell** world,int kolumny,int wiersze){
	int k,w;
		for(w=0 ; w<wiersze ; w++){
			for(k=0 ; k<kolumny ; k++){
				if(world[w][k].alive==1){
					if((world[w][k].mate==2)||(world[w][k].mate==3)){
						world[w][k].alive=1;
					}
					else{
						world[w][k].alive=0;
					}
				}
				else{
					if(world[w][k].mate==3){
						world[w][k].alive=1;
					}
				}
			}
		}
}

void fill_from_file(cell*** world,int* kolumny,int* wiersze,char* place){

	FILE *plik=NULL;
	int kol=*kolumny,wier=*wiersze,k,w;
	cell life={1,0};

	plik = fopen(place,"r");

	if (plik == NULL){
		perror("blad otwarcia pliku");
		exit(-10);
	}

	printf("rozpoczynam odczyt\n");

	while(feof(plik) == 0){
		fscanf(plik,"%d",&w);
		fscanf(plik,"%d",&k);

		if(w>wier){
		  resize(world,kol,wier,kol,w+1);
		  wier=w+1;
		}

		if(k>kol){
		  resize(world,kol,wier,k+1,wier);
		  kol=k+1;
		}

		insert(*world,k,w,life);
	}

	fclose(plik);

	*kolumny=kol;
	*wiersze=wier;
}

void save_to_file(cell** world,int kolumny,int wiersze,char* place){
	FILE *plik=NULL;
	int k,w;

	plik = fopen(place,"w"); 		//tryb zapisu "w" jedna runda "a" wszystkie rundy

	if (plik == NULL){
		  perror("blad otwarcia pliku");
		  exit(-10);
	}

	if (world==NULL){
		  perror("Tablica nie istnieje");
		  exit(-10);
	}
	else{

		for (w=0 ; w<wiersze ; w++){

			for (k=0 ; k<kolumny ; k++){

				if(world[w][k].alive==1){
					fprintf(plik,"%d ",w);
					fprintf(plik,"%d ",k);
					fprintf(plik,"\n");
				}
			}
		}
	}

	fprintf(plik,"\n\n");
	fclose(plik);

}
