
#include "../lib/heap.h"

heap* create_heap()
{
    heap* new_heap = (heap*) malloc(sizeof(heap));
    new_heap->size = 0;
    return new_heap;
}

int is_empty(heap *heap)
{
    if(heap->size == 0)
    {
        return 1;
    }
    return 0;
}

int get_parent_index(heap* heap, int index)
{
    return index >> 1;
}

int get_left_index(heap* heap, int index)
{
    return index << 1;
}

int get_right_index(heap* heap, int index)
{
    return (index<<1)+1;
}

int item_of(heap *heap, int index)
{
    return heap->data[index];
}

void swap(int* a, int* b)
{
    int aux;
    aux = *a;
    *a   = *b;
    *b   = aux;
}


void  max_heapify(heap *heap, int index, int* comp_heap)
{
    int highest;
    int left_index  = get_left_index (heap ,index);
    int right_index = get_right_index(heap, index);

    if(left_index <= heap->size && heap->data[left_index] > heap->data[index])
    {
        (*comp_heap)++;
        highest = left_index;
    }
    else
    {
        highest = index;
    }
    if(right_index <= heap->size && heap->data[right_index] > heap->data[highest])
    {
        (*comp_heap)++;
        highest = right_index;
    }
    if(heap->data[index] != heap->data[highest])
    {
        swap(&heap->data[index], &heap->data[highest]);
        (*comp_heap)++;
        max_heapify(heap, highest, &(*comp_heap));
    }
}

void dequeue(heap* heap, int* comp_heap)
{
    if(is_empty(heap))
    {
        printf("Heap underflow\n");
        return -1;
    }
    else
    {
        int item = heap->data[1];
        heap->data[1] = heap->data[heap->size];
        heap->size--;
        max_heapify(heap, 1, &(*comp_heap));
    }
}

void enqueue(heap *heap, int item, int* comp_heap)
{
    if(heap->size >= MAX_SIZE)
    {
        printf("Heap overflow\n");
    }
    else
    {
        heap->data[++heap->size] = item;

        int key_index = heap->size;
        int parent_index = get_parent_index(heap, heap->size);

        while(parent_index >= 1 && heap->data[key_index] < heap->data[parent_index] )
        {
            (*comp_heap)++;
            swap(&heap->data[key_index], &heap->data[parent_index]);

            key_index = parent_index;

            parent_index = get_parent_index(heap, key_index);

        }
    }
}
