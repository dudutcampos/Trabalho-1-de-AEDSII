#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "bucketsort.h"
#define ZERO 0

// Argumentos da função. 
// 1ª = função a ser usado nos intervalos do bucketsort.
// 2ª = vetor a ser ordenado.
// 3ª = numero de elementos do vetor.
// 4ª = intervalos do bucketsort.
// 5ª = determina se a função de ordenação tenha inicio com n ou (n-1) elementos.
//             |            1ª            |   2ª  |  3ª  |    4ª    |  5ª  |
void bucketsort(void (*f) (int*, int, int), int *v, int n, int inter, int l){
    
    int min, max, bk;
    min = v[ZERO];
    max = v[ZERO];
    // achando maior e menor valor no vetor *v.
    for (int i = 0; i < n; i++){
        if (v[i] > max) max = v[i];
        if (v[i] < min) min = v[i];
    }
    //definindo tamanho do intervalo.
    bk = (max - (min - 1))/inter;
    if (max%inter){
        bk++;
    }
    
    int inf = min - 1;
    int sup = inf + bk;

    Lista *lista = criaL();
    //separando em intervalos.
    for (int i = 0; i < inter; i++){
        int s[n];
        int tam = 0;
        for (int j = 0; j < n; j++){
            if(v[j] > inf && v[j] <= sup){
                s[tam] = v[j];
                tam++;
            }
        }
        //inserindo novo intervalo na lista.
        insere(lista, tam, s);        
        inf = sup;
        sup = sup + bk;
    }
    
    Bucket *b = lista->primeiro->prox;
    int j = 0;
    for (int i = 0; i < inter; i++){
        //ordenando cada bucket na função selecionada.
        f(b->buck, ZERO, (b->tam - l));
        //mesclando buckets no vetor *v.
        for (int i = 0; i < b->tam; i++){
            v[j] = b->buck[i];
            j++;
        }
        b = b->prox;
    }   
    desfazer(lista);
}