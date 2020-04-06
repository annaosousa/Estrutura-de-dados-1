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
int numero (const char* num)
{
    if(num >= '0' && num <= '9')
        return 1;
    return 0;
}

void posFixa(const char* infixa)
{
    Stack* p = create_stack (strlen(infixa));

    int i;

    for (;*infixa;infixa++)
    {
        if(numero(*infixa))
            putchar(*infixa);
        else if(!numero(*infixa))
        {
            if(*infixa == '*' || *infixa == '+')
                push(p,*infixa);
            else if (*infixa == ')')
            {
                putchar(pop(p));
            }
        }
    }
    free_stack(p);
}
