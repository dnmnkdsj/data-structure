//
// Created by 张震宇 on 2018/1/11.
//
#include "hash_SepChain.h"
/****implementation file****/

typedef int ElementType;
struct ListNode {
	ElementType element;
	struct ListNode * next;
};
typedef Position *List;
typedef struct _hashTable {
	int size;
	int full;
	double load_factor;
	List lists;
} hashTable;

int hash(ElementType element,HashTable hashTable) {
	return element % hashTable->size;
}
HashTable initializeTable(int tableSize){
	HashTable hash;
	if (tableSize < 1) {
		Error("size 0");
		return NULL;
	}

	//allocate space
	hash = (HashTable) malloc(sizeof(hashTable));
	if (hash == NULL) {
		FatalError("out of space");
	}
	hash->size = tableSize;
	hash->full = 0;
	hash->load_factor = (double) hash->full / hash->size;
	//allocate lists
	hash->lists = malloc(sizeof(List) * hash->size);
	for (int i = 0; i < hash->size; i++) {
		hash->lists[i] = (List) malloc(sizeof(List));
		hash->lists[i]->next = NULL;
	}
}
Position find(ElementType key,HashTable hashTable) {
	int pos = hash(key, hashTable);
	Position p = hashTable->lists[pos]->next;
	while (p != NULL) {
		if (p->element == key) {
			return p;
		}
		p = p->next;
	}
	printf("%d is not in hash table.", key);
	return NULL;
}
void insert(ElementType key,HashTable hashTable) {
	int pos = hash(key, hashTable);
	Position inser = (Position) sizeof(struct ListNode);
	inser->next = hashTable->lists[pos]->next;
	inser->element = key;
	hashTable->lists[pos]->next = inser;
	hashTable->full++;
	hashTable->load_factor = ((double) hashTable->full) / (double) hashTable->size;
	if (hashTable->load_factor >= 3 / 4) {
		reHash(hashTable);
	}
}
void delete(ElementType key,HashTable hashTable) {
	int pos = hash(key, hashTable);
	Position p = hashTable->lists[pos]->next;
	Position re = hashTable->lists[pos];
	while (p != NULL) {
		if (p->element == key) {
			break;
		}
		re = p;
		p = p->next;
	}
	re->next = p->next;
	free(p);
}
HashTable reHash(HashTable hashTable) {
	HashTable newHash = initializeTable((hashTable->size + 1) * 2 - 1);
	for (int i = 0; i < hashTable->size; i++) {
		Position pos = hashTable->lists[i]->next;
		while (pos) {
			insert(pos->element, newHash);
		}
	}
}
