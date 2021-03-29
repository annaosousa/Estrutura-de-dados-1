#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int info;
   struct node* next;
} Lista;

Lista* criar (void);

Lista* inserir (Lista *lista, int elem);

void imprimir (Lista *lista);

Lista *remover (Lista *l, int elem);

void liberar (Lista *l);

