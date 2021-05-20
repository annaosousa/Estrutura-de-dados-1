#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Imprimir (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf ("\n");
}

void Swap (int *i, int *j) {
  int aux = *i;
  *i = *j;
  *j = aux;
}

int particione (int *vetor, int esq, int dir){
    int pivo = vetor[dir];
    int i = esq - 1;

    for (int j = esq; j < dir; j++){
        if (vetor[j] < pivo){
            i ++;
            Swap(&vetor[i],&vetor[j]);
        }
    }
    Swap(&vetor[i+1], &vetor[dir]);
    //printf("%d",i+1);
    return (i+1);
}

int QuickFind (int *vetor, int esq, int dir, int k) {
    if (dir > esq){
        int q = particione(vetor, esq, dir);

        if (q == k)
            return vetor[q];

        else if (q < k)
            QuickFind(vetor, esq+1, dir, k);

        else
            QuickFind(vetor, esq, dir-1, k);
    }
}


/*Função principal.*/
int main (int argc, char *argv[]) {
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int i;

   //int tamanho = 10;
   //int *vetor = (int *)malloc(tamanho * sizeof(int));
   //for (i = 0; i < tamanho; i++) {
   //   vetor[i] = rand() % (tamanho+1);
   //}

   int tamanho = 8;
   int vetor[] = {7, 1, 3, 10, 17, 2, 21, 9};

   Imprimir (vetor, tamanho);
   start = clock();
   int pos = 2;
   printf("O elemento procurado na posicao %d e %d\n", pos, QuickFind(vetor, 0, tamanho-1, pos));
   for(int i=0; i<tamanho;i++)
   {
        printf("%d ", vetor[i]);
   }

   end = clock();
   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   //free (vetor);
   return 0;
}
