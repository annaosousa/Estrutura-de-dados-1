#include "deck.h"

Deck* createDeck () {
  return NULL;
}

/*Função que retorna a coordenada armazenada na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getFront (Deck *d) {
   if (d != NULL)
   {
       return d->p;
   }
}

/*Função que retorna a coordenada armazenada na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Point getRear (Deck *d) {
   if (d != NULL)
   {
       while (d->next != NULL)
       {
            d = d->next;
       }
   }

   return d->p;
}

/*Função para inserir na cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertFront (Deck *d, Point p, char field[][SIZE]) {
   Deck* novo = (Deck*)malloc(sizeof(Deck));
   novo->p = p;
   novo->next = d;
   novo->prev = NULL;
   field[p.x][p.y] = '*';/*Ponto inserido faz parte do corpo da Snake!*/

   if (d != NULL)
   {
       d->prev = novo;
   }

   return novo;

}

/*Função para inserir na cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* insertRear (Deck *d, Point p, char field[][SIZE]) {
   Deck* novo = (Deck*)malloc(sizeof(Deck));
   novo->p = p;
   novo->next = NULL;
   novo->prev = NULL;
   field[p.x][p.y] = '*';/*Ponto inserido faz parte do corpo da Snake!*/

    Deck* aux = d;
   if (d != NULL)
   {
       while (aux->next != NULL)
       {
            aux = aux->next;
       }
       aux->next = novo;
       novo->prev = aux;
       return d;
   }

    return novo;
}

/*Função para remover a cabeça da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteFront (Deck *d, char field[][SIZE]) {
   Deck *aux;
   if (d != NULL)
   {
       field[d->p.x][d->p.y] = ' '; /*Ponto eliminado agora é marcado como vazio!*/
       aux = d->next;
       aux->prev = NULL;

       free(d);
       return aux;
   }
    else
    {
        return NULL;
    }
}

/*Função para remover a cauda da lista encadeada (assuma que o endereço do Deck *d aponta para a cabeça)!*/
Deck* deleteRear (Deck *d, char field[][SIZE]) {
    Deck *aux = d;
   if (d != NULL)
   {
       while (aux->next != NULL)
       {
            aux = aux->next;
       }
       field[d->p.x][d->p.y] = ' '; /*Ponto eliminado agora é marcado como vazio!*/
       aux->prev->next = NULL;
       free(aux);
       return d;
   }
   else
   {
       return NULL;
   }
}


