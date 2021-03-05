#include <stdio.h>
#include <stdlib.h>

typedef struct _fila {
   int inicio;
   int fim;
   int tam;
   int *vetor;
} Fila;

Fila* criar_fila (int fila_tamanho) {
   /*Para implementar uma fila sem struct era necessário um malloc para alocar
   o vetor com os elementos. Note que agora são necessários dois mallocs, um
   para a estrutura tipo fila e outro para o vetor que a fila contém!*/
   Fila* f = (Fila *)malloc(sizeof(Fila));
   f->inicio = 0;
   f->fim = 0;
   f->tam = fila_tamanho;
   f->vetor = (int *)malloc(fila_tamanho * sizeof(int));
}

void destruir_fila (Fila *f) {
   /*Para cada malloc da função criar_fila é necessário um free!*/
   free(f->vetor);
   free(f);
}

void enqueue (Fila *f, int elemento) {
   /*Criar uma lógica para armazenar o elemento na posição
   fim (que está dentro da variável tipo fila f e dentro do
   vetor que também está dentro da variável f)!
   Lembre de deixar a variável fim apontando
   para a próximo posição livre na fila.*/
   f->vetor[f->fim] = elemento;
    (f->fim)++;
}

int dequeue (Fila *f) {
   /*Criar uma lógica para remover o elemento na posição
   ini (que está dentro da variável tipo fila f e dentro do
   vetor que também está dentro da variável f) e retornar
   este valor! Lembre de deixar a variável ini apontando
   para o próximo elemento da fila.*/
   int elemento = f->vetor[f->inicio];
    (f->inicio)++;
    return elemento;
}

int main () {

   /*Inicializando a estrutura de dados fila!*/
   Fila *fila = criar_fila (10);

   /*Tentando inserir o elemento 1 na fila!*/
   int elem = 1;
   enqueue (fila, elem);

   /*Tentando inserir o elemento 2 na fila!*/
   elem = 2;
   enqueue (fila, elem);

   /*Tentando inserir o elemento 3 na fila!*/
   elem = 3;
   enqueue (fila, elem);

   /*Tentando inserir o elemento 4 na fila!*/
   elem = 4;
   enqueue (fila, elem);

   /*Tentando retirar e imprimir o elemento 1 na fila!*/
   printf("%d\n", dequeue (fila));

   /*Tentando retirar e imprimir o elemento 2 na fila!*/
   printf("%d\n", dequeue (fila));

   destruir_fila (fila);

   return 0;
}
