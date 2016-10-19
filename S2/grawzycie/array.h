#ifndef ARRAY
#define ARRAY

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct komorka {
	int alive;
	int mate;
}cell;

cell** create(int kolumny, int wiersze);
void delate(cell*** wsk, int wiersze);
void resize(cell*** wsk,int stare_w,int stare_k,int nowe_w, int nowe_k);
void clear_all(cell** plansza,int kolumny,int wiersze);
void clear_mate(cell** plansza,int kolumny,int wiersze);
int at(cell** plansza,int kolumny,int wiersze);
void insert(cell** tablica,int kolumny,int wiersze,cell wartosc);
void print_array(cell** tablica,int kolumny,int wiersze);


#endif
