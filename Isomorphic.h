//
// Created by 张震宇 on 2018/1/3.
//
#include <stdbool.h>
#include "binary_tree.h"

#ifndef LAB_BETA_ISOMORPHIC_H_
#define LAB_BETA_ISOMORPHIC_H_
bool isomorphic(Root tree1,Root tree2) {
	if (!tree1 && !tree2) {
		return true;
	} else if ((tree1 && !tree2) || (tree2 && !tree1)) {
		return false;
	} else if (tree1->data != tree2->data) {
		return false;
	} else if (isomorphic(tree1->left, tree2->right) && isomorphic(tree1->right, tree2->left)) {
		return true;
	} else if (isomorphic(tree1->left, tree2->left) && isomorphic(tree1->right, tree2->right)) {
		return true;
	}
	return false;
}
#endif; //LAB_BETA_ISOMORPHIC_H_
