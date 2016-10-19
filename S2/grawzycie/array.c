#include "array.h"


cell** create(int kolumny, int wiersze){
	cell** wsk=NULL;
	int i;

	wsk =(cell**)malloc(sizeof(cell*) * (wiersze));

	if(wsk==NULL){
		  perror("blad alokacji pamieci");
		  exit(-10);
	}

	for(i=0 ; i<wiersze ; i++){
		wsk[i]=(cell*)malloc(sizeof(cell) * (kolumny));

		if(wsk[i]==NULL){
			  perror("blad alokacji pamieci");
			  exit(-10);
		}

	}

	clear_all(wsk,kolumny,wiersze);		//czyszczenie przypadkowych danych, zerowanie obydwy zmiennych w cell'u
	return wsk;

}

void delate(cell*** wsk,int wiersze){
	int i;

	for(i=0;i<wiersze;i++){
	   free((*wsk)[i]);
	}

	free(*wsk);

}

void resize(cell*** wsk,int stare_k,int stare_w, int nowe_k, int nowe_w){
	cell** ptr=NULL;
	int k,w,temp_k=stare_k,temp_w=stare_w;

	ptr=create(nowe_k,nowe_w);

	if(nowe_k<stare_k){		//czy nowa tablica jest wieksza czy mniejsza?
		temp_k=nowe_k;		//sprawdzam zeby nie zapisac pozniej nieprzydzelonej
	}

	if(nowe_w<stare_w){
		temp_w=nowe_w;
	}

	for(w=0;w<temp_w;w++){

		for(k=0 ; k<temp_k ; k++){
			ptr[w][k].alive=(*wsk)[w][k].alive;
			ptr[w][k].mate=(*wsk)[w][k].mate;
		}

	}

	delate(wsk,stare_w);
	**wsk=ptr;

}

void clear_all(cell** plansza,int kolumny,int wiersze){
	int k,w;

	for(w=0 ; w<wiersze ; w++){

		for(k=0 ; k<kolumny ; k++){
			plansza[w][k].alive=0;
			plansza[w][k].mate=0;
		}
	}
}

void clear_mate(cell** plansza,int kolumny,int wiersze){
	int k,w;

	for(w=0 ; w<wiersze ; w++){

		for(k=0 ; k<kolumny ; k++){
			plansza[w][k].mate=0;
		}
	}
}

int at(cell** plansza,int kolumny,int wiersze){

	return plansza[wiersze][kolumny].alive;

}

void  insert(cell** tablica,int kolumny,int wiersze,cell wartosc){

	tablica[wiersze][kolumny].alive=wartosc.alive;
	tablica[wiersze][kolumny].mate=wartosc.mate;

}

void print_array(cell** tablica,int kolumny,int wiersze){

	if (tablica==NULL){
		  perror("Tablica nie istnieje");
		  exit(-10);
	}
	else{
		int i=0, j=0;
		for (i=0 ; i<wiersze ; i++)
		{
			for (j=0 ; j<kolumny ; j++){
				if(tablica[i][j].alive){
					printf("%2c",'o');
				}
				else{
					printf("%2c",'.');
				}
			}
			printf("\n");
		}
	}
}
