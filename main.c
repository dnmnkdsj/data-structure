#include <stdio.h>
#include "binary_tree.h"
#include "construct_tree.h"


int main() {
	//construct a tree with length limitation
	int length = 15;
	TreeType preorder[] = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15};
	TreeType inorder[] = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15};
	Root root = construct(preorder, inorder, length);
	printf("construct successful!\n");
	//print tree with level-order traversal
	leverOrderTraverse(root);
	return 0;
}