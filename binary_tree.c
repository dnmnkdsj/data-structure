/*
 *  implement of binary tree header file
 */
#include <stdio.h>
#include "binary_tree.h"

/**
 * foundations
 */
printData(int data) {
	printf("%d", data);
}

/**initialization**/
/**
 * @return an ampty binary tree
 */
Root initTree() {
	Root ret =
			(Root) malloc(sizeof(TreeNode));
	ret->data = 0;
	ret->left = NULL;
	ret->right = NULL;
	return ret;
}
/**
 * @param root
 * @return left and right child tree
 */
Root left(Root root){
	return root->left;
}
Root right(Root root) {
	return root->right;
}
/**traverse**/
void preOrderTraverse(Root root){
	printData(root->data);
	if (root->left) {
		preOrderTraverse(root->left);
	}
	if (root->right) {
		preOrderTraverse(root->right);
	}
}
void inOrderTraverse(Root root){
	if (root->left) {
		inOrderTraverse(root->left);
	}
	printData(root->data);
	if (root->right) {
		inOrderTraverse(root->right);
	}
}
void postOrderTraverse(Root root){
	if (root->left) {
		postOrderTraverse(root->left);
	}
	if (root->right) {
		postOrderTraverse(root->right);
	}
	printData(root->data);
}

void leverOrderTraverse(Root root) {
	Queue *queue = initQueue();
	printData(root->data);
	if (root->left) {
		enqueue(queue, root->left);
	}
	if (root->right) {
		enqueue(queue, root->right);
	}
	while (queue->size) {
		TreeNode *tmp = dequeue(queue);
		printData(tmp->data);
		if (tmp->left) {
			enqueue(queue, tmp->left);
		}
		if (tmp->right) {
			enqueue(queue, tmp->right);
		}
	}
}

