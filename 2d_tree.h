//
// Created by 张震宇 on 2018/1/5.
//
#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>
#include <string.h>

#ifndef LAB_BETA_2D_TREE_H_
#define LAB_BETA_2D_TREE_H_

#define KeyType char

typedef struct tree_2d
{
	KeyType *key1;
	KeyType *key2;
	struct tree_2d *leftChild;
	struct tree_2d *rightChild;
} Tree_2d;

/**
 * conditional traversal
 * @param t
 * @param low1
 * @param high1
 * @param low2
 * @param high2
 * @param level
 */
void conditionalTraversal(Tree_2d *t , KeyType *low1 , KeyType *high1 , KeyType *low2 , KeyType *high2,int level )
{
	if ( NULL == t ) return ;
	else if
			(strcmp(t->key1 , low1) > 0 && strcmp(t->key1 , high1) < 0 && strcmp(t->key2 , low2) > 0 && strcmp(t->key2 , high2) < 0)
		printf("%s %s \n", t->key1 ,t->key2);

	if ( level % 2 == 0)
	{
		if ( strcmp(t->key1 , low1) < 0 )
			conditionalTraversal( t->rightChild , low1 , high1 , low2 , high2 ,level + 1);
		else if ( strcmp(t->key1 , high1) > 0)
			conditionalTraversal( t->leftChild , low1 , high1 , low2 , high2 ,level + 1);
		else {
			conditionalTraversal( t->rightChild , low1 , high1 , low2 , high2 ,level + 1);
			conditionalTraversal( t->leftChild , low1 , high1 , low2 , high2 ,level + 1);
		}
	} else {
		if ( strcmp(t->key2 , low2) < 0 )
			conditionalTraversal( t->rightChild , low1 , high1 , low2 , high2 ,level + 1);
		else if ( strcmp(t->key2 , high2) > 0 )
			conditionalTraversal( t->leftChild , low1 , high1 , low2 , high2 ,level + 1);
		else {
			conditionalTraversal( t->rightChild , low1 , high1 , low2 , high2 ,level + 1);
			conditionalTraversal( t->leftChild , low1 , high1 , low2 , high2 ,level + 1);
		}
	}

}

/**
 * insert function
 * @param newKey1
 * @param newKey2
 * @param b
 * @param level
 * @return
 */
Tree_2d *insert(KeyType *newKey1 , KeyType *newKey2, Tree_2d *b,int level)// insert a node whose keys are newKeys
{
	if (b == NULL)
	{
		b = malloc (sizeof (Tree_2d));
		b->key1 = newKey1;
		b->key2 = newKey2;
		b->leftChild = NULL;
		b->rightChild = NULL;
	}

	else if ( level % 2 == 0)
	{
		if ( strcmp( newKey1 , b->key1 ) > 0 )
			b->rightChild = insert( newKey1,newKey2 ,  b->rightChild, level + 1 );
		else if ( strcmp( newKey1 , b->key1 ) < 0 )
			b->leftChild = insert(  newKey1,newKey2 ,  b->leftChild , level + 1 );
		else if ( strcmp( newKey1 , b->key1 ) == 0 )
		{
			if ( strcmp( newKey2 , b->key2 ) > 0 )
				b->rightChild = insert( newKey1 , newKey2 , b->rightChild , level + 1 );
			else if ( strcmp( newKey2 , b->key2 ) < 0)
				b->leftChild = insert( newKey1 , newKey2 , b->leftChild , level + 1 );
		}
		return b;
	} else{
		if ( strcmp( newKey2 , b->key2 ) > 0)
			b->rightChild = insert( newKey1,newKey2 ,  b->rightChild, level + 1 );
		else if ( strcmp( newKey2 , b->key2 ) < 0 )
			b->leftChild = insert(  newKey1,newKey2 ,  b->leftChild , level + 1 );
		else if ( strcmp( newKey2 , b->key2 ) == 0)
		{
			if ( strcmp( newKey1 , b->key1 ) > 0)
				b->rightChild = insert( newKey1 , newKey2 , b->rightChild , level + 1 );
			if ( strcmp( newKey1 , b->key1 ) < 0)
				b->leftChild = insert( newKey1 , newKey2 , b->leftChild , level + 1 );
		}
		return b;
	}

}

#endif //LAB_BETA_2D_TREE_H_
