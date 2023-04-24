#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ordenacao.h"
// returna o tipo de ordenação interna do bucketsor.
int tipoOrdenacao(char*);

int main(){
    // declarando ponteiro para funções    0         1          2         3        4
    void (*f[5])(int*, int, int) ={quicksort, heapsort, mergeSort, insercao, selecao};
    //n = numero de elementos.
    //inter = numero de partições do bucketsort.
    //e = indice do ponteiro f[].    
    int n, inter, e;
    //tipo = tipo de ordenação a ser realizada internamente.
    char tipo[10];
    char *ptipo = &tipo[0];
    
    while (scanf(" %d", &n) != EOF){
        // encerra programa.
        if(n == 0){
            break;
        }
        
        //alocando v para receber n elementos.
        int *v = (int*)malloc(n*sizeof(int));

        for (int i = 0; i < n; i++){
            scanf(" %d", &v[i]);
        }
        
        scanf(" %s %d", ptipo, &inter);

        // selecionando ordenação.
        e = tipoOrdenacao(ptipo);
        
        // l = 1 caso a função de ordenação tenha inicio com (n-1) elementos.
        int l = 0;
        if(e == 0 || e == 2) l = 1;
 
        bucketsort(f[e], v, n, inter, l);    
        for (int i = 0; i < n; i++){
            printf("%d ", v[i]);
        }
        printf("\n");
        // liberando a memorio de *v.
        free(v);
    }
    
    return 0;      
}

int tipoOrdenacao(char *ptipo){
    int e;
    if(strcmp(ptipo, "quicksort") == 0) e = 0;
    if(strcmp(ptipo, "heapsort") == 0) e = 1;
    if(strcmp(ptipo, "mergesort") == 0) e = 2;
    if(strcmp(ptipo, "insercao") == 0) e = 3;
    if(strcmp(ptipo, "selecao") == 0) e = 4;
    return e;
}