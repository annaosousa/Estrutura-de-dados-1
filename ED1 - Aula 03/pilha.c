#include "pilha.h"

/*Função para criar uma pilha!*/
Pilha* create_stack (int tam) {
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->topo = 0;
  p->tam = tam;
  p->vetor = (int *)malloc(tam * sizeof(int));
  return p;
}

/*Função para empilhar um elemento!*/
void push (Pilha *p, int elem) {
  if (full_stack(p)) {
    printf ("Pilha cheia\n");
    exit(1);
  }
  p->vetor[p->topo] = elem;
  p->topo++;
}

/*Função para desempilhar um elemento!*/
int pop (Pilha *p) {
  if (empty_stack(p)) {
    printf ("Pilha vazia\n");
    exit(1);
  }
  p->topo--;
  return p->vetor[p->topo];
}

/*Função para liberar a memória alocada.*/
int empty_stack (Pilha *p) {
  return (p->topo ==  0);
}

/*Funão para testar se a pilha está cheia!*/
int full_stack (Pilha *p) {
  return (p->topo == p->tam);
}

/*Funão para testar se a pilha está vazia!*/
void destroy_stack (Pilha *p) {
  free(p->vetor);
  free(p);
}

int bemFormada (char* seq)
{
    Pilha* p = create_stack(strlen(seq));

    for(int i = 0; i < strlen(seq); i++)
    {
        if(seq[i] == '(' || seq[i] == '[')
        {
            push(p, seq[i]);
        }
        else if (seq[i] == ')')
        {
            if(pop(p) == '(');
        }
        else if (seq[i] == ']')
        {
            if(pop(p) == '[');
        }
        else
            return 0;
    }

    if (!empty_stack(p))
    {
        free(p);
        return 0;
    }

    free(p);
    return 1;

}

int verifica_palindromo (char *palavra)
{
    Pilha* p = create_stack (strlen(palavra));
    int i;

    for (i = 0 ;i < strlen(palavra);i++)
        push(p,palavra[i]);

    for (i = strlen(palavra); i >= 0; i--)
        printf("%c", palavra[i]);

    for (i = 0 ; i < strlen(palavra);i++)
    {
        if(palavra[i] != pop(p))
            return 0;
    }

    free(p);

    return 1;
}


