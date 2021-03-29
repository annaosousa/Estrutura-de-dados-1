#include "lista.h"
#include <time.h>

/*Função para ...*/
Lista* procurar (Lista* lista, int elem) {
   Lista *v;

    for (v = lista; v != NULL; v = v->next) {
        if(v->info == elem)
            return v;
    }

   return NULL;
}

Lista* separa (Lista* lista, int n) {
    Lista *v = lista;
    Lista *v2 =  NULL;

    if (lista != NULL)
    {
        v2 = procurar(lista, n)->next;
        procurar(lista,n)->next= NULL;
        return v2;
    /* for (v = lista; v != NULL; v = v->next) {
            if(v->info == n)
            {
                v2 = v->next;
                v->next = NULL;
                return v2;
            }
   }*/
    }

   return NULL;
}

int main () {
   int v;
   Lista *lista1 = criar ();
   srand(time(NULL));

   printf("Gerando numeros aleatorios e inserindo na cabeca ate que o sorteio nao seja 7!\n");
   do {
      v = rand() % 15;
      lista1 = inserir (lista1, v);
   } while (v != 7);

   printf("Lista 1 antes da separacao:\n");
   imprimir (lista1);

   printf ("Digite o elemento na separacao: ");
   scanf ("%d", &v);

   Lista *lista2 = separa (lista1, v);

   printf("Lista 1 depois da separacao:\n");
   imprimir (lista1);

   printf("Lista 2 depois da separacao:\n");
   imprimir (lista2);

   /*Desalocando listas!*/
   liberar (lista1);
   liberar (lista2);
   return 0;
}
