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
   aux.data=a.data;
   aux.priority=a.priority;
   a.data=b.data;
   a.priority=b.priority;
   b.data=aux.data;
   b.priority=aux.priority;
}


void heap_push(Heap* pq, void* data, int priority){
  int a=pq->size;
  if(pq->size == pq->capac){
    pq->heapArray=realloc(pq->heapArray,2*(pq->capac)+1);
  }
  pq->heapArray[a].data=data;
  pq->heapArray[a].priority= priority;
  

  while (pq->heapArray[a].priority > pq->heapArray[(a-1)/2].priority)
  {
     swap(pq->heapArray[a],pq->heapArray[(a-1)/2]);
     a=(pq->size-1)/2;
  }
  pq->size++;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
   /*
   Heap * h=malloc(sizeof(Heap));
   heapElem h->heapArray=calloc(3,sizeof(heapElem));
   h->size=0;
   h->capac=3;
   */
   return NULL;
}