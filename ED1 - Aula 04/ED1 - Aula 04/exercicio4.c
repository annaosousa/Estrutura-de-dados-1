#include "lista.h"
#include <time.h>
/* Exerc�cio Proposto

Implemente uma fun��o que construa uma nova lista com a intercala��o dos n�s de outras duas listas passadas como
par�metros. Essa fun��o deve retornar a lista resultante.
Essa fun��o deve obedecer ao prot�tipo:
Lista* merge(Lista* l1, Lista *l2).

Exerc�cio do livro: Introdu��o a estrutura de dados com t�cnicas de programa��o em C, dos autores: Celes, Cerqueira e Rangel.
Capitulo 10, exerc�cio 2.7 (pag. 216)

*/
Lista* merge(Lista* lista1, Lista* lista2)
{
    Lista *v = criar();
    Lista *v1 = lista1;
    Lista *v2 = lista2;

    if( lista1!= NULL && lista2 != NULL)
    {
         while((v1 != NULL) && (v2!= NULL))
        {
            v = inserir(v, v1->info);
            v = inserir(v, v2->info);
            v1 = v1->next;
            v2 = v2->next;
        }
        return v;
    }
    return NULL;
}

int main () {
   Lista *lista1 = criar ();
   Lista *lista2 = criar ();

   lista1 = inserir (lista1, 1);
   lista1 = inserir (lista1, 2);
   lista1 = inserir (lista1, 4);

   lista2 = inserir (lista2, 5);
   lista2 = inserir (lista2, 6);
   lista2 = inserir (lista2, 7);

   printf("Elementos presentes na lista 1:\n");
   imprimir (lista1);
   printf("Elementos presentes na lista 2:\n");
   imprimir (lista2);

   Lista *resultado = merge (lista1, lista2);
   if (resultado != NULL) {
      printf ("\nElementos presentes na lista 3 (intercalada):\n");
      imprimir(resultado);
   }
   else {
      printf ("Elemento nao encontrado!\n");
   }

   liberar (lista1);
   liberar (lista2);
   //liberar (lista3);
   return 0;
}
