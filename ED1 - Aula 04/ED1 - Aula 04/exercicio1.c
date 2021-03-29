#include "lista.h"
#include <time.h>

/*Função para ...*/
int conta_nos (Lista* lista) {
   Lista *v;
   int cont = 0;

   if (lista != NULL)
   {
      for (v = lista; v != NULL; v = v->next) {
      cont++;
       }
   }

   return cont;
}

int main () {
   int v;
   Lista *lista = criar ();
   srand(time(NULL));

   do {
      v = rand() % 15;
      lista = inserir (lista, v);
   } while (v != 12);

   printf("Elementos sorteados:\n");
   imprimir (lista);
   printf("\n");
   printf("Numero de nos: %d\n", conta_nos(lista));
   liberar (lista);
   return 0;
}
