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



void prin(Heap * pq){
   int i;
   for(i=0;i<pq->size;i++){
      printf("-%d-",pq->heapArray[i].priority);
   }
}

void heap_push(Heap* pq, void* data, int priority){
  if(pq->size == pq->capac){
    int NuevaCap=(pq->capac)*2+1;    
    pq->heapArray=realloc(pq->heapArray,NuevaCap);
    pq->capac=NuevaCap;
  }
  pq->heapArray[pq->size].data=data;
  pq->heapArray[pq->size].priority= priority;
  int a=pq->size;

  while (pq->heapArray[a].priority > pq->heapArray[(a-1)/2].priority)
  {
      //printf("%d---%d\n",pq->heapArray[a].priority,pq->heapArray[(a-1)/2].priority);
      heapElem aux;
      aux.data=pq->heapArray[a].data;
      aux.priority=pq->heapArray[a].priority;
      pq->heapArray[a].data=pq->heapArray[(a-1)/2].data;
      pq->heapArray[a].priority=pq->heapArray[(a-1)/2].priority;
      pq->heapArray[(a-1)/2].data=aux.data;
      pq->heapArray[(a-1)/2].priority=aux.priority;
      //printf("%d---%d\n",pq->heapArray[a].priority,pq->heapArray[(a-1)/2].priority);
      a=(a-1)/2;
  }

  pq->size++;
}


void heap_pop(Heap* pq){
   prin(pq);
   heapElem* aux=(heapElem *)malloc(sizeof(heapElem));
   printf("\n");
   pq->heapArray[0].data=pq->heapArray[pq->size-1].data;
   pq->heapArray[0].priority=pq->heapArray[pq->size-1].priority;
   pq->size--;

   int a=0;

   while(a < pq->size){
      if(pq->heapArray[a].priority < pq->heapArray[a*2+1].priority && pq->heapArray[a*2+1].priority > pq->heapArray[a*2+2].priority){
         *aux=pq->heapArray[a];
         pq->heapArray[a] = pq->heapArray[a*2+1];
         pq->heapArray[a*2+1] = *aux;

         a=a*2+1;
         continue;
      }
      if(pq->heapArray[a].priority < pq->heapArray[a*2+2].priority && pq->heapArray[a*2+2].priority > pq->heapArray[a*2+1].priority ){
         *aux=pq->heapArray[a];
         pq->heapArray[a] = pq->heapArray[a*2+2];
         pq->heapArray[a*2+2] = *aux;

         a=a*2+2;
         continue;

      }
      else break;
   }   
}

Heap* createHeap(){
   Heap * h=(Heap *) malloc(sizeof(Heap));
   h->heapArray=(heapElem *)calloc(3,sizeof(heapElem));
   h->size=0;
   h->capac=3;
   return h;
}   