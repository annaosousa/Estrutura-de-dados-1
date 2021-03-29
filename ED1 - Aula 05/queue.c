#include "queue.h"

/*Função para criar uma fila vazia (não criar nenhum nó, só devolver NULL)!*/
Queue* create_queue () {

   return NULL;
}

/*Função para liberar uma fila nó por nó!*/
void free_queue (Queue *q) {

   Queue *aux;

   while (q != NULL)
   {
       aux = q->next;
       free(q);
       q = aux;
   }
}

/*Função para enfileirar um elemento (inserir na cauda da lista encadeada)!*/
Queue* enqueue (Queue *q, int elem) {

   Queue *n = (Queue*)malloc(sizeof(Queue));
   Queue *aux;

   n->info = elem;
   n->next = NULL;

   if (q == NULL)
   {
       q = n;
       return q;
   }
    aux = q;

    while(aux->next != NULL)
    {
        aux = aux->next;
    }
    aux->next = n;

    return aux;
}

/*Função para desenfileirar um elemento (remover da cabeça da lista encadeada)!*/
Queue* dequeue (Queue *q) {

   Queue *aux;

   if (empty_queue(q))
   {
       printf("Fila vazia\n");
       exit(1);
   }

   aux = q;
   q = q->next;
   aux->next = NULL;

   free(aux);
   return q;

}

/*Função para retornar o primeiro elemento da fila (cabeça da lista encadeada) sem desenfileirar!*/
int front (Queue *q) {

   return q->info;
}

/*Função para testar se uma fila está vazia!*/
int empty_queue (Queue *q) {

   return (q->next == NULL);
}

