#include "heapsort.h"
void heapsort(int *v, int a, int n) {
    heap_constroi(v, n);

    int k = n;
    while(k >= 1) {
        int aux = v[k - 1];
        v[k - 1] = v[0];
        v[0] = aux;
        k--;
        refaz_cima_baixo(v, 1, k);
    }
}
//0 1 2 3 4 5 6  7
//5 6 9 1 2 3 10 11
//1 2 3 4 5 6 7  8                4      8
void refaz_cima_baixo(int *v, int k, int N) {
    int j;
    while(2*k <= N) {
        j = 2*k;
        
        if(j < N && v[j - 1] < v[j]) {
            j++; 
        }

        if(v[k - 1] >= v[j - 1]) { 
            break; 
        }
        int aux = v[k - 1];
        v[k - 1] = v[j - 1];
        v[j - 1] = aux;
        k = j;
    }
}

void heap_constroi(int *v, int n) {
    int k = (n/2);
    while(k >= 1) {
        refaz_cima_baixo(v, k, n);
        k--;
    }
}