//
// Created by 张震宇 on 2018/1/2.
//
#include "binary_tree.h"

#ifndef LAB_BETA_CONSTRUCT_TREE_H_
#define LAB_BETA_CONSTRUCT_TREE_H_
/**
 * fundatios
 */
int find(TreeType a[],int length,TreeType target) {
	for (int i = 0; i < length; i++) {
		if (a[i] == target) {
			return i;
		}
	}
	//not found
	return (-1);
}
/******functions*******/
TreeNode * construct(TreeType a[],TreeType b[],int length) {
	TreeNode *root = initTree();
	if (!length) {
		return (NULL);
	}
	root->data = a[0];
	//find leftchild's elements in a,b array and then divide into two part to construct
	int leftLength = find(b, length, a[0]);
	root->left = construct(a + 1, b, leftLength);
	root->right = construct(a + leftLength + 1, b + leftLength + 1, length - leftLength - 1);
	return root;
}
#endif //LAB_BETA_CONSTRUCT_TREE_H_
