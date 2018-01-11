//
// Created by 张震宇 on 2018/1/11.
//

#ifndef LAB_BETA_HASH_SEPCHAIN_H_
#define LAB_BETA_HASH_SEPCHAIN_H_
struct ListNode;
typedef struct ListNode *Position;
struct _hashTable;
typedef hashTable *PtrToHashTable;
typedef PtrToHashTable HashTable;

/**functions**/
/**
 * initialize function
 * @param tableSize
 * @return
 */
HashTable initializeTable(int tableSize);
/**
 * find
 * @param key
 * @param hashTable
 * @return
 */
Position find(ElementType key,HashTable hashTable);
/**
 * insert
 * @param key
 * @param hashTable
 */
void insert(ElementType key,HashTable hashTable);
/**
 * delete
 * @param key
 * @param hashTable
 */
void delete(ElementType key,HashTable hashTable);
/**
 * reHash
 * @param hashTable
 * @return
 */
HashTable reHash(HashTable hashTable);
#endif //LAB_BETA_HASH_SEPCHAIN_H_
