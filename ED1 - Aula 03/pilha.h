#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
  int topo;
  int tam;
  int *vetor;
} Pilha;

typedef struct calc{
    char f[21];
    Pilha *p;
}Calc;

Pilha* create_stack (int tam);

void push (Pilha *p, int elem);

int pop (Pilha *p);

int empty_stack (Pilha *p);

int full_stack (Pilha *p);

void destroy_stack (Pilha *p);

int bemFormada (char* seq);

int verifica_palindromo (char *palavra);
