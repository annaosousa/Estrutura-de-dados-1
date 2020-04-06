#include "Pilha.h"
#include <string.h>

Stack* create_stack (int size)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->vector = (int *)malloc(size * sizeof(int));
    p->top = 0;
    p->size = size;

    return p;
}

void push(Stack *p,const char *elem)
{
    if (full(p)) {
    printf("pilha cheia: capacidade esgotada\n");
    exit(1); /*aborta programa*/
    }
    p->vector[p->top] = elem; /*insere elemento*/
    p->top++; /*incrementa o topo*/
}

int pop (Stack *p)
{
    if (empty(p)) {
    printf("pilha vazia!\n");
    exit(1); /*aborta programa*/
    }
    p->top--; /*decrementa o ´ındice do topo.*/
    return p->vector[p->top]; /*retorna o ele. do topo*/
}

int empty (Stack *p) //verifica se a pilha esta vazia
{
    return (p->top == 0);
}

int full (Stack *p) //verifica se a pilha esta cheia
{
    return (p->top == p->size);
}

void free_stack (Stack *p) //libera a memoria alocada
{
    free(p->vector);
    free(p);
}


//exercicio
int verifica_palindromo (char *palavra)
{
    Stack* p = create_stack (strlen(palavra));
    int i;

    for (i = 0 ;i < strlen(palavra);i++)
        push(p,palavra[i]);

    for (i = 0 ; i < strlen(palavra);i++)
    {
        if(palavra[i] != pop(p))
            return 0;
    }


    free_stack (p);

    return 1;
}
