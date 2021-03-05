#include <stdio.h>
#include <stdlib.h>

/*NAO USE VARIAVEIS GLOBAIS!!!!!!!!!!!!!*/

/*Fun��o para enfileirar um dado elemento em um vetor: */
void enqueue (int vetor[], int elemento, int tamanho, int *fim) {
   /*As entradas na funcao sao suficientes para inserir
    *um elemento na fila? Precisa de mais alguma coisa?
    -> n�o s�o suficientes, falta o fim da fila(onde o elemento � inserido)*/

   /*Como voce faz para inserir um elemento na fila? Veja
    *nos slides a logica. Em qual posicao voce insere?*/
    vetor[*fim] = elemento;
    (*fim)++;

}

/*Fun��o para desenfileirar um dado elemento em um vetor: */
int dequeue (int vetor[], int tamanho, int *inicio) {
   /*As entradas na funcao sao suficientes para retirar
    *um elemento da fila? Precisa de mais alguma coisa?
    -> n�o � suficiente, para retirar um elemento da fila � necess�rio o in�cio (FIFO)*/

   /*Como voce faz para remover um elemento na fila? Veja
    *nos slides a logica. De qual posicao voce remove?*/
    int elemento = vetor[*inicio];
    (*inicio)++;
    return elemento;
}

int main () {

   int elem;

   /*Determinando o tamanho da fila!*/
   int fila_tamanho = 10;
   int inicio = 0;
   int fim = 0;

   /*Reservando o espaco para o vetor na memoria!*/
   int *fila = (int *)malloc(fila_tamanho * sizeof(int));

   /*Tentando inserir o elemento 1 na fila!*/
   elem = 1;
   enqueue (fila, elem, fila_tamanho, &fim);

   /*Tentando inserir o elemento 2 na fila!*/
   elem = 2;
   enqueue (fila, elem, fila_tamanho, &fim);

   /*Tentando inserir o elemento 3 na fila!*/
   elem = 3;
   enqueue (fila, elem, fila_tamanho, &fim);

   /*Tentando inserir o elemento 4 na fila!*/
   elem = 4;
   enqueue (fila, elem, fila_tamanho, &fim);

   /*Tentando retirar e imprimir o elemento 1 na fila!*/
   printf("%d\n", dequeue (fila, fila_tamanho, &inicio));

   /*Tentando retirar e imprimir o elemento 2 na fila!*/
   printf("%d\n", dequeue (fila, fila_tamanho, &inicio));

   free(fila);

   return 0;
}

