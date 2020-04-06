#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct _Stack {
    int top;
    int size;
    int *vector;
} Stack;

Stack* create_stack (int size); //cria a pilha
void push (Stack *p, const char* elem); //insere novo elemento
int pop (Stack *p); //retira elemento
int empty (Stack *p); //verifica se a pilha está vazia
int full (Stack *p); //verifica se a pilha esta cheia
void free_stack (Stack *p);


#endif // PILHA_H_INCLUDED
