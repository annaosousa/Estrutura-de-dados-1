#include <stdio.h>
#include <stdlib.h>

typedef struct _fila {
   int inicio;
   int fim;
   int tam;
   int *vetor;
} Fila;

Fila* criar_fila (int fila_tamanho) {
   /*Para implementar uma fila sem struct era necess�rio um malloc para alocar
   o vetor com os elementos. Note que agora s�o necess�rios dois mallocs, um
   para a estrutura tipo fila e outro para o vetor que a fila cont�m!*/
   Fila* f = (Fila *)malloc(sizeof(Fila));
   f->inicio = 0;
   f->fim = 0;
   f->tam = fila_tamanho;
   f->vetor = (int *)malloc(fila_tamanho * sizeof(int));
}

void destruir_fila (Fila *f) {
   /*Para cada malloc da fun��o criar_fila � necess�rio um free!*/
   free(f->vetor);
   free(f);
}

void enqueue (Fila *f, int elemento) {
   /*Criar uma l�gica para armazenar o elemento na posi��o
   fim (que est� dentro da vari�vel tipo fila f e dentro do
   vetor que tamb�m est� dentro da vari�vel f)!
   Lembre de deixar a vari�vel fim apontando
   para a pr�ximo posi��o livre na fila.*/
   f->vetor[f->fim] = elemento;
    (f->fim)++;
}

int dequeue (Fila *f) {
   /*Criar uma l�gica para remover o elemento na posi��o
   ini (que est� dentro da vari�vel tipo fila f e dentro do
   vetor que tamb�m est� dentro da vari�vel f) e retornar
   este valor! Lembre de deixar a vari�vel ini apontando
   para o pr�ximo elemento da fila.*/
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
