#ifndef GAME
#define GAME

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include "array.h"

void generate_round(cell** world,int wiersze, int kolumny);
void caculate_mate(cell** world,int kolumny,int wiersze);
void born(cell** world,int kolumny,int wiersze);
void fill_from_file(cell*** world,int *kolumny,int *wiersze,char* place);
void save_to_file(cell** world,int kolumny,int wiersze,char* place);


#endif
