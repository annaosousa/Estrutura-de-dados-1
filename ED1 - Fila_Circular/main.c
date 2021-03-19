#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main (int argc, char *argv[]) {

   int tam = 100;
   int i = 0;

   /*Crie uma fila com tam + 1 elementos para armazenar os elementos pares!*/
   Fila *fila_par = create_queue (tam+1);
   /*Crie uma fila com tam + 1 elementos para armazenar os elementos ĩmpares!*/
   Fila *fila_impar = create_queue (tam+1);

   /*Com um while e rand produza tam elementos aleatórios*/
   while(i < tam)
   {
        int n = rand()%51;

        if(n%2 == 0)
        {
            enqueue(fila_par, n);
        }
        else
        {
            enqueue(fila_impar, n);
        }
        i++;
   }
   /*Cada elemento aleatório sorteado deve ser inserido com enqueue OU na fila dos pares OU na fila dos ĩmpares!*/
   /*Não tem problema se as filas ficarem com metade das posições ocupadas!*/

   /*Use a funcao empty e dequeue para retirar cada elemento da fila dos pares e imprima-os ate que a fila fique vazia!*/
   while(!empty(fila_par))
   {
        printf("Fila par: %d\n", dequeue(fila_par));
   }

   /*Use a funcao empty e dequeue para retirar cada elemento da fila dos impares e imprima-os ate que a fila fique vazia!*/
   while(!empty(fila_impar))
   {
        printf("Fila impar: %d\n", dequeue(fila_impar));
   }


   free_queue (fila_par);
   free_queue (fila_impar);
   return 0;
}


