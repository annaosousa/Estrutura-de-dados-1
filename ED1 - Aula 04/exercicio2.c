#include "lista.h"
#include <time.h>

/*Função que dado um elemento retorna o endereço do nó na lista encadeada que contém aquele elemento!*/
Lista* procurar (Lista* lista, int elem) {
   Lista *v;

   if(lista != NULL)
   {
      for (v = lista; v != NULL; v = v->next) {
        if(v->info == elem)
            return v;
      }
   }

   return NULL;
}


int main () {
   Lista *lista = criar ();
   srand(time(NULL));

   printf("Gerando dez numeros aleatorios!\n");
   int i = 0;
   while (i < 10) {
      int sorteio = rand() % 100;
      lista = inserir (lista, sorteio);
      i++;
   }

   printf("Elementos sorteados e presentes na lista:\n");
   imprimir (lista);

   printf ("Digite um elemento que deseja procurar na lista: ");
   int valor;
   scanf ("%d", &valor);

   Lista *resultado = procurar (lista, valor);
   if (resultado != NULL) {
      printf ("Elemento encontrado no endereco: %p\n", resultado);
   }
   else {
      printf ("Elemento nao encontrado!\n");
   }

   liberar (lista);

   return 0;
}
