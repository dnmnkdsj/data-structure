#include <stdio.h>
#include "2d_tree.h"

int main() {
	//import examples
	char examples[10][2][20];
	//create 2d tree
	Tree_2d *a = NULL;
	//insert 2d tree
	for (int i = 0; i < 10; ++i) {
		a = insert( examples[i][0],examples[i][1] , a , 0 );
	}
	//conditional traversal
	conditionalTraversal( a , "A" , "ZZZZZZZ" , "H" , "ZZZZZZ" ,0);
	return 0;
}