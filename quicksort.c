#include "quicksort.h"

void quicksort(int *v, int e, int d) {
   if(d <= e) return;
   int p = particao(v, e, d);
   quicksort(v, e, p-1);
   quicksort(v, p+1, d);
}

int particao(int *v, int e, int d) {
   int i = e; 
   int j = d; 
   int pivo = (d+e)/2;
   while(1) { 
      while(v[i] < v[pivo]) i++;
      while(v[pivo] < v[j]) j--;
      if(i >= j) break;

      int aux = v[i];
      v[i] = v[j];
      v[j] = aux;
   }
   return i;
}