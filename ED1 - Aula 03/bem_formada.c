#include <string.h>
#include "pilha.h"

int main () {

   /*Utilize as funções da TAD pilha na resolução do exercício!
    *Resolver do ponto de vista de aplicação, ou seja, não acesse
    *os dados internos da pilha nesta resolução (NÃO use ->), apenas
    *push, pop, empty, ... */

   char *seq = "[ ( ) ] [ )"; /*Suponha que a string esta armazenada em um string!*/
    //(()[()])   -> pilha bem formada
   int i = 0;

   while (seq[i] != '\0') {
      printf ("%c", seq[i]);

      i++;
   }

   printf(bemFormada(seq)? "\nPilha bem formada":"\nPilha mal formada");
   return 0;
}

