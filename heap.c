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
  if(pq->size == 0)
    return NULL;
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  int posicion = pq->size;
  heapElem aux;
  int padre = (posicion-1)/2;
  if(pq->size == pq->capac)
  {
    pq->heapArray = realloc(pq->heapArray, sizeof(heapElem) * pq->capac);
    pq->capac = (pq->capac*2)+1;
  }
  pq->heapArray[pq->size].data = data;
  pq->heapArray[pq->size].priority = priority;
  pq->size++;
  while(pq->heapArray[posicion].priority > pq->heapArray[padre].priority)
  {
    if(pq->heapArray[posicion].priority > pq->heapArray[padre].priority)
    {
      aux = pq->heapArray[posicion];
      pq->heapArray[posicion] = pq->heapArray[padre];
      pq->heapArray[padre] = aux;
      posicion = padre;
      padre = (posicion-1)/2;
    }
    
  }
}


void heap_pop(Heap* pq)
{
  int pos = 0;
  if(pq->size == 0) return;
  pq->heapArray[0] = pq->heapArray[pq->size-1];
  pq->size--;
  while(1)
  {
    int hijo1 = 2*pos+1;
    int hijo2 = 2*pos+2;
    int mayor = 0;
    heapElem aux;
    if (hijo1 >= pq->size && hijo2 >= pq->size) break;
    if(pq->heapArray[hijo1].priority > pq->heapArray[hijo2].priority)
      mayor = hijo1;
    else mayor = hijo2;
    if(pq->heapArray[mayor].priority > pq->heapArray[pos].priority)
    {
      aux = pq->heapArray[mayor];
      pq->heapArray[mayor] = pq->heapArray[pos];
      pq->heapArray[pos] = aux;
      pos = mayor;
    }
    else break;
  }
}

Heap* createHeap(){
  Heap *nuevoHeap;
  nuevoHeap = malloc(3 * sizeof(Heap));
  nuevoHeap->heapArray = malloc(3 * sizeof(Heap));
  nuevoHeap->size = 0;
  nuevoHeap->capac = 3;
  return nuevoHeap;
}
