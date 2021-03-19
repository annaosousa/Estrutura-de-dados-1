#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "Fila.h"

int main (int argc, char *argv[]) {

   int tam = 1;
   char doc;
   int escolha, op;

   Fila *fila_espera = create_queue (tam+1);
   Fila *fila_imprime = create_queue (tam+1);

    while( empty(fila_imprime)){
        printf("Selecione o documento(A,B,C): ");
        scanf(" %c", &doc);
        fflush(stdin);

       if(empty(fila_imprime))
       {
           enqueue(fila_imprime, doc);
           printf("Imprimindo: %c\n ",doc);
           Sleep(500);
           system("cls");
       }
    }

    printf("Deseja imprimir mais: 1 - sim/ 2 - nao \n");
    scanf(" %d", &op);

    if (op == 1)
    {
        if (full(fila_imprime))
        {
            enqueue(fila_espera, doc);
            printf("Impressora em uso, documento na fila de espera!\n");
            Sleep(1000);
        }
        printf("\nAinda deseja imprimir: 1 - sim/ 2 - nao \n");
        scanf(" %d", &escolha);

        if (escolha == 1)
        {
           dequeue(fila_imprime);
           Sleep(500);

           printf("Imprimindo: %c \n", dequeue(fila_espera));
       }
       Sleep(100);
    }

    printf("Processo finalizado");


   while(!empty(fila_espera))
   {
        dequeue(fila_espera);
   }


   free_queue (fila_espera);
   free_queue (fila_imprime);
   return 0;
}

