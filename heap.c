#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
   if (pq->size==0){
      return NULL;
   }
  return pq->heapArray[0].data;
}

void swap(heapElem  a,heapElem  b){
   heapElem aux;
   printf("%d -- %d\n",a.priority,b.priority);
   aux.data=a.data;
   aux.priority=a.priority;
   a.data=b.data;
   a.priority=b.priority;
   b.data=aux.data;
   b.priority=aux.priority;
   printf("%d -- %d\n",a.priority,b.priority);
}


void heap_push(Heap* pq, void* data, int priority){
  if(pq->size == pq->capac){
    pq->heapArray=realloc(pq->heapArray,2*(pq->capac)+1);
  }
  pq->heapArray[pq->size].data=data;
  pq->heapArray[pq->size].priority= priority;

  while (pq->heapArray[pq->size].priority > pq->heapArray[(pq->size-1)/2].priority)
  {
     swap(pq->heapArray[pq->size],pq->heapArray[(pq->size-1)/2]);
     pq->size=(pq->size-1)/2;
  }
  pq->size++;
}


void heap_pop(Heap* pq){
   swap(pq->heapArray[0],pq->heapArray[pq->size]);
   pq->heapArray[pq->size].data=NULL;
   pq->heapArray[pq->size].priority=NULL;
}

Heap* createHeap(){
   Heap * h=(Heap *) malloc(sizeof(Heap));
   h->heapArray=(heapElem *)calloc(3,sizeof(heapElem));
   h->size=0;
   h->capac=3;
   return h;
}