typedef struct bucket Bucket;
typedef struct lista Lista;

struct bucket{
    int *buck;
    int tam;
    Bucket *prox;
};
struct lista{
    Bucket *primeiro;
    Bucket *ultimo;
};

Lista* criaL();
int vazia(Lista*);
void insere(Lista*, int, int[]);
void desfazer(Lista*);