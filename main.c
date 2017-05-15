#include "lib/heap.h"
#include "lib/priority_queue.h"

int main()
{
  int i;
  int comp = 0;
  int priority;
  priority_queue* pq = create_pQueue();
  heap* heap = create_heap();
  char command[20];

  scanf("%s",command);

  if(!(strcmp(command,"enqueue")))
  {
    srand(time(NULL));
    FILE* output = fopen("heap_enqueue.csv","w");

    for(i = 0; i < 25000; i++)
    {
      priority = rand();
      enqueue(heap,priority,&comp);
      fprintf(output,"%d,%d\n",comp,heap->size);
      comp = 0;
    }

    fclose(output);

    output = fopen("pq_enqueue.csv","w");

    for(i = 0; i < 25000; i++)
    {
      priority = rand();
      enqueue_pQueue(pq,priority,&comp);
      fprintf(output,"%d,%d\n",comp,pq->size);
      comp = 0;
    }
    fclose(output);
    printf("Fim\n");
  }
  else if(!(strcmp(command,"dequeue")))
  {
    srand(time(NULL));

    for(i = 0; i < 25000; i++)
    {
      priority = (rand() % 99)+1;
      enqueue(heap,priority,&comp);
      enqueue_pQueue(pq,priority,&comp);
    }
    printf("\n");
    comp = 0;

    FILE* output = fopen("heap_dequeue.csv","w");

    for(i = 0; i < 25000; i++)
    {
      dequeue(heap,&comp);
      fprintf(output,"%d,%d\n",comp,heap->size);
      comp = 0;
    }

    fclose(output);

    output = fopen("pq_dequeue.csv","w");

    for(i = 0; i < 25000; i++)
    {
      dequeue_pQueue(pq,&comp);
      fprintf(output,"%d,%d\n",comp,pq->size);
      comp = 0;
    }
    fclose(output);
    printf("Fim\n");
  }
  return 0;
}
