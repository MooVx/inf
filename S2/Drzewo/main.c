#include "tree.h"



int main(){
	char* place="wiki.txt";
	node* root=NULL;
	system("clear");
	createnode(&root);
	choice(root,place);
	free_tree(root);

	return 0;
}


