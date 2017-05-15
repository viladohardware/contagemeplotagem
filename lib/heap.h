#ifndef HEAP_H
#define HEAP_H

#define MAX_SIZE 1000000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct heap
{
    int size;
    int data[MAX_SIZE];
    char elemento[128];
} heap;

heap* create_heap();

int is_empty(heap *heap);

int get_parent_index(heap* heap, int index);

int get_left_index(heap* heap, int index);

int get_right_index(heap* heap, int index);

int item_of(heap *heap, int index);

void swap(int* a, int* b);

void max_heapify(heap *heap, int index, int* comp_heap);

void dequeue(heap* heap, int* comp_heap);

void enqueue(heap *heap, int item, int* comp_heap);

#endif
