#include "tree.h"

void createnode(node**branch){
	node* newnode=NULL;
	newnode=(node*)malloc(sizeof(node));
	dane zaw={"Nowy Kontakt","Nowy Kontakt",0};
	if(newnode==NULL){
		  perror("blad alokacji pamieci");
		  exit(-10);
	}
	newnode->data=zaw;
    newnode->left=NULL;
    newnode->right=NULL;
    *branch=newnode;
}

void printnode(node* branch){
    printf("\nNazwisko:  %s\n", branch->data.nazwisko);
    printf("    Imie:  %s\n", branch->data.imie);
    printf("   Numer 1:  %ld\n", branch->data.nr1);
    printf("   Numer 2:  %ld\n", branch->data.nr2);
}

void printinorder(node* root){
    if (root->left!=NULL){
    	printinorder(root->left);
    }
    printnode(root);
    if (root->right!=NULL){
    	printinorder(root->right);
    }
}

void maxvalue(node* root){
	if(root==NULL){
		return;
	}
	while(root->right!=NULL){
		root=root->right;
	}
	printnode(root);
}

void minvalue(node* root){
    if(root==NULL){
    	return;
    }
    while(root->left!=NULL){
    	root=root->left;
    }
    printnode(root);
}

void insert(node* root,dane zawartosc){
	int l=0,r=0,check=0;
	node* wsk;
	node* temp;
	wsk=root;
	if(strcmp(wsk->data.nazwisko,"Nowy Kontakt")==0){
		root->data=zawartosc;
	}
	else{
		temp=wsk;
		while(!(temp==NULL)){
			wsk=temp;
			check=strcmp(zawartosc.nazwisko,wsk->data.nazwisko);
			l=0;
			r=0;
			if(check<0){
				temp=wsk->left;
				l=1;
			}
			if(check>0){
				temp=wsk->right;
				r=1;
			}
			if(check==0){
				check=strcmp(zawartosc.imie,wsk->data.imie);		//strcmpi zamiast strcmp ignoruje rozmiar liter
				if (check<0){
					temp=wsk->left;
					l=1;
				}
				if (check>=0){
					temp=wsk->right;
					r=1;
				}
			}
		}
		if(l==1){
			createnode(&(wsk->left));
			(wsk->left->data)=zawartosc;
		}
		if(r==1){
			createnode(&(wsk->right));
			(wsk->right->data)=zawartosc;
		}
	}
}

void enter_data(dane* osoba){
    printf("Podaj nazwisko:  ");
    scanf("%s",osoba->nazwisko);
    printf("Podaj imie:      ");
    scanf("%s",osoba->imie);
    printf("Podaj numer1:     ");
    scanf("%ld",&(osoba->nr1));
    printf("Podaj numer2:     ");
    scanf("%ld",&(osoba->nr2));

}

void filltree(node* root,char* place){
	FILE *plik=NULL;
	dane zawartosc;
	plik = fopen(place,"r");
	while(feof(plik) == 0){
		fscanf(plik,"%s",zawartosc.nazwisko);
		fscanf(plik,"%s",zawartosc.imie);
		fscanf(plik,"%ld",&(zawartosc.nr1));
		fscanf(plik,"%ld",&(zawartosc.nr2));
		insert(root,zawartosc);
	}
}

int numberofnodes(node* root){
    if(root == NULL) return 0;
    return (numberofnodes(root->left)+numberofnodes(root->right))+1;
}

void search(node *root,char* key){

    if(root==NULL){
    	printf("brak takiego kontaktu");
    	return;
    }
    int check=strcmp(key,root->data.nazwisko);

    if(check<0){
    	search(root->left,key);
    }
    else if(check==0){
    	printnode(root);
    }
    else if(check>0){
    	search(root->right,key);
    }
}

int treelevel(node* root){
    if (root==NULL){
    	return 0;
    }
    if ((root->left==NULL)&&(root->right==NULL)){
    	return 1;
    }
    if ((root->left==NULL)&&(root->right!=NULL)){
    	return (1+treelevel(root->right));
    }
    if ((root->left!=NULL)&&(root->right==NULL)){
    	return (1+treelevel(root->left));
    }
    if ((root->left!=NULL)&&(root->right!=NULL)){
        if (treelevel(root->right)>=treelevel(root->left)){
        	return (1+treelevel(root->right));
        }
        if (treelevel(root->right)<treelevel(root->left)){
        	return (1+treelevel(root->left));
        }
    }
    return -1; //nie spelniono warunkow cos jest nie tak
}

/***dodatkowe********************************************/

void printpreorder(node* root){
    printnode(root);
    if (root->left!=NULL){
    	printpreorder(root->left);
    }
    if (root->right!=NULL){
    	printpreorder(root->right);
    }
}

void free_tree(node* root){
    if (root->left!=NULL){
    	free_tree(root->left);
    }
    if (root->right!=NULL){
    	free_tree(root->right);
    }
   free(root);

}

void choice(node* root,char* place){
	dane osoba;
	char key[20];
	int i=0,j=1,n=1;

	printf("jak chcesz dodac osoby?\n");
		printf("1 - plik\n");
		printf("2 - klawiatura\n");
		scanf("%d",&i);
		switch(i){
			case 1:
				filltree(root,place);
				printf("wpisalem.\n");
			break;
			case 2:
				printf("ile osob?\n");
				scanf("%d",&j);
				while(j!=0){
					enter_data(&osoba);
					insert(root,osoba);
					printf("wpisalem.\n");
					j--;
				}
			break;
			default:
				printf("zly wybor\n");
		}

		system("clear");

		while(n){
			i=0;
			printf("\n\n ****** \n\n");
		    printf("\nCo robimy ?\n");
		    printf("dodaj kontakt:				1\n");
		    printf("Wypisz in-order:			2\n");
		    printf("szukaj :				3\n");
		    printf("Aby wyswietlic minimum :		4\n");
		    printf("Aby wyswietlic maksimum :		5\n");
		    printf("wysokosc drzewa:			6\n");
		    printf("liczba danych:				7\n");
		    printf("Wypisz pre-order:			8\n");
		    printf("\n *** nacisnij cos innego aby wyjsc *** \n");
		    scanf("%d",&i);
		    system("clear");
		    switch(i){
		        case 1:
		        	printf("ile osob?\n");
						scanf("%d",&j);
						while(j!=0){
							enter_data(&osoba);
							insert(root,osoba);
							printf("wpisalem.\n");
							j--;
						}
				break;
		        case 2:
		            printinorder(root);
		        break;
		        case 3:
					printf("\n Podaj nazwisko do wyszukania: \n");
					scanf("%s",key);
					search(root,key);
		        break;
		        case 4:
		        	printf("max:\n");
		        	maxvalue(root);
		        break;
		        case 5:
		        	printf("max:\n");
		        	minvalue(root);
		        break;
		        case 6:
		        	printf("wysokosc drzewa: %2d",treelevel(root));
		        break;
		        case 7:
			        printf("liczba wenzlow: %2d",numberofnodes(root));
		        break;
		        case 8:
			        printpreorder(root);
		        break;
		        default:
		        	n=0;
		        	printf("wychodze.\n");
		        break;
		    }
		}
}
