#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_pQueue
{
    int priority;
    struct node_pQueue* next;
} node;

typedef struct priority_queue
{
  node* head;
  int size;
} priority_queue;

priority_queue* create_pQueue();

int is_empty_pQueue(priority_queue* pq);

void enqueue_pQueue(priority_queue *pq, int p, int* comparacoes_pQueue);

node* dequeue_pQueue(priority_queue *pq, int* comp);

#endif
