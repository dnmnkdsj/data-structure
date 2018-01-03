//
// Created by 张震宇 on 2018/1/2.
//
#include <stdlib.h>
#include "queue.h"

/*******functions*******/
/**
 * initialize a queue
 * @return a new empty queue
 */
PtrToQueue initQueue() {
	PtrToQueue ret =
			(PtrToQueue) malloc(sizeof(Queue));
	ret->size = 0;
	ret->front = NULL;
	ret->rear = NULL;
	return ret;
}
//enqueue & dequeue
void enqueue(Queue *queue, QueueType element) {
	QueueNode *tmp =
			(QueueNode *) malloc(sizeof(QueueNode));
	tmp->element = element;
	tmp->next = NULL;
	queue->size++;
	//insert element into an empty array
	if (queue->size == 1) {
		queue->front = tmp;
		queue->rear = tmp;
	} else {
		queue->rear->next = tmp;
		queue->rear = tmp;
	}
}
QueueType dequeue(Queue * queue) {
	QueueNode *tmp = queue->front;
	queue->size--;
	//delete element from an array with only one element
	if (queue->size == 0) {
		queue->rear = NULL;
	}
	queue->front = tmp->next;
	QueueType ret = tmp->element;
	free(tmp);
	return ret;
}