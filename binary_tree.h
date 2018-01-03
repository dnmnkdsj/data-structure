/*
 * This is a binary tree, use integer as element type.
 * Author:  张震宇
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef LAB_BETA_BINARY_TREE_H_
#define LAB_BETA_BINARY_TREE_H_
/********definitions*******/
typedef int TreeType;
typedef struct _TreeNode {
	TreeType data;
	struct _TreeNode * left;
	struct _TreeNode * right;
}TreeNode;
typedef TreeNode *PtrToTreeNode;
typedef PtrToTreeNode Root;
typedef PtrToTreeNode Node;

/**
 * definition with other header files
 */
#ifndef QUEUE_TYPE
#define QUEUE_TYPE TreeNode *
#endif
#include "queue.h"

/*******functions*******/
/**initialization**/
Root initTree();
/**node**/
Root left(Root root);
Root right(Root root);
/**traverse**/
void preOrderTraverse(Root root);
void inOrderTraverse(Root root);
void postOrderTraverse(Root root);
void leverOrderTraverse(Root root);

#endif //LAB_BETA_BINARY_TREE_H_
