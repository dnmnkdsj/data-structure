//
// queue header file, with necessary functions
//

/**
 * use queue to offer functions for other usage
 * and define type from other header file
 * which may cause code below shows inactive status in some ide
 * but they can work fine, I tried.
 */
#include "binary_tree.h"
#ifndef QUEUE_TYPE
#define QUEUE_TYPE int
#endif

typedef QUEUE_TYPE QueueType;

#ifndef LAB_BETA_QUEUE_H_
#define LAB_BETA_QUEUE_H_
/*******definitions*******/
typedef struct _QueueNode {
	QueueType element;
	struct _QueueNode * next;
}QueueNode;
typedef struct _Queue {
	QueueNode *front;
	QueueNode *rear;
	int size;
} Queue;
typedef Queue *PtrToQueue;

/*******functions*******/
/**
 * initialize a queue
 * @return a new empty queue
 */
PtrToQueue initQueue();
//enqueue & dequeue
/**
 * enqueue
 * @param queue
 * @param element
 */
void enqueue(Queue *queue, QueueType element);
/**
 * dequeue
 * @param queue
 * @return
 */
QueueType dequeue(Queue * queue);
#endif //LAB_BETA_QUEUE_H_
