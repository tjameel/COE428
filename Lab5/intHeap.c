#include <stdlib.h>
#include <stdio.h>

int size = 0;
int heap[1000];

/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
    int var;
    var = heap[0];
    heap[size] = var;
    heap[0] = heap[size];
    size--;
    printf("%d\n", heap[size]);
    return heap[size];
 
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
    heap[size] = thing2add;
    size++;
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
    return heap[size]; // A dummy return statement
}
void heapXML(int node){
    if(node <= heapSize()){
        
        heapXML(node*2);
        heapXML((node*2)+1);
        fprintf(stderr, "<node id=\"%d\">", heap[node]);
        fprintf(stderr, "</node>");
    }
}