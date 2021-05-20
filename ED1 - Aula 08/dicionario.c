#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Troca dois elementos strings {i,j} de posição.*/
void Swap (char **A, int i, int j) {
  char *aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

void Ordena (char **A, int l, int r) {
    for (int i = l; i < r; i++){
        int aux = i;
        for(int j = i+1; j <= r; j++){
            if (strcmp(A[j],A[aux]) <= 0){
                Swap(A,i,j);
            }
        if (i != aux){
            Swap(A,i,j);
            }
        }
    }
}

/*Função para contar o número de linhas de um arquivo.*/
int conta_linhas (FILE *arq) {
  int linhas = 0;
  if (arq == NULL) {
    return linhas;
  }
  while (!feof(arq)) {
    char c;
    fscanf(arq, "%c", &c);
    if (c == '\n') {
      linhas++;
    }
  }
  rewind(arq);
  return (linhas-1);
}

/*Função principal.*/
int main (int argc, char *argv[]) {
   srand(time(NULL));

   /*Abrindo o arquivo:*/
   FILE *arq = fopen("palavras.txt", "r"); //fopen(argv[1],"r");

   /*Contando o número de linhas do arquivo:*/
   int linhas = conta_linhas(arq);
   printf("O numero de linhas do arquivo e: %d\n", linhas);

   /*Alocando memória para armazenar as palavras:*/
   char **palavras = (char **)malloc(linhas * sizeof(char *));
   int i;
   for (i = 0; i < linhas; i++) {
      palavras[i] = (char *)malloc(256 * sizeof(char));
   }

   /*Lendo as palavras do arquivos:*/
   i = 0;
   while (!feof(arq)) {
      fscanf(arq, "%s", palavras[i]);
      i++;
   }

   /*Ordenando as palavras:*/
   clock_t start = clock();
   Ordena (palavras, 0, linhas-1);
   clock_t end = clock();
   double elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   printf("Tempo de execução: %.2f\n", elapsed_time);

   /*Imprimindo as palavras:*/
   for (i = 0; i < linhas; i++) {
      printf("%s\n", palavras[i]);
   }

   /*Liberando a memória:*/
   for (i = 0; i < linhas; i++) {
      free(palavras[i]);
   }
   free(palavras);
   fclose(arq);
   return 0;
}

