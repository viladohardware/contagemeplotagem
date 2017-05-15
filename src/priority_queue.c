#include "../lib/priority_queue.h"


priority_queue* create_pQueue()
{
  priority_queue* new_queue = malloc(sizeof(priority_queue));
  (*new_queue).head = NULL;
  (*new_queue).size = 0;
  return new_queue;
}

int is_empty_pQueue(priority_queue* pq)
{
    if(pq->head == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueue_pQueue(priority_queue *pq, int p, int* comparacoes_pQueue)
{
    node *new_node = (node*) malloc(sizeof(node));
    new_node->priority = p;

    if ((is_empty_pQueue(pq)) || (p > pq->head->priority))
    {
        new_node->next = pq->head;
        pq->head = new_node;
        (*comparacoes_pQueue)++;
        (pq->size)++;
    }
    else
    {
        node *current = pq->head;

        while (((*comparacoes_pQueue)+= 1) && (current->next != NULL) && (current->next->priority > p))
        {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
        (pq->size)++;
    }
}

node* dequeue_pQueue(priority_queue *pq, int* comp)
{
    if (is_empty(pq))
    {
        printf("Priority Queue underflow");
        return NULL;
    }
    else
    {
        node *node = pq->head;
        pq->head = pq->head->next;
        node->next = NULL;
        (pq->size)--;
        return node;
    }
}
