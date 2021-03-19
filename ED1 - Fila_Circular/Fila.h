#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct fila {
   int ini; /*guarda o inicio da fila*/
   int fim; /*guarda o fim da fila*/
   int tam; /*tamanho da fila*/
   int *vetor; /*vetor de elementos inteiros*/
} Fila;

int empty (Fila *f);
int full (Fila *f);
Fila* create_queue (int tam);
void enqueue (Fila *f, int e);
int dequeue (Fila *f);
void free_queue (Fila *f);


#endif // FILA_H_INCLUDED
