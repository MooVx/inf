#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//#include <windows.h>

/***struktury********************************************/

typedef struct {
	char imie[30];
	char nazwisko[30];
	long nr1;
	long nr2;
}dane;

typedef struct wenzel{
	dane data;
	struct wenzel* left;
	struct wenzel* right;
}node;

/***funkcje**********************************************/

void createnode(node** branch);
void printnode(node* branch);
void printinorder(node* root);
void maxvalue(node* root);
void minvalue(node* root);
void insert(node* root,dane data);
void filltree(node* root,char* place);
void enter_data(dane* osoba);
int numberofnodes(node* root);
void search(node* root,char* key);
int treelevel(node* root);

/***dodatkowe********************************************/

void printpreorder(node* root);
void free_tree(node* root);
void choice(node* root,char* place);

#endif /* TREE_H_ */
