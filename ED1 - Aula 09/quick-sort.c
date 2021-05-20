#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Aleatoria:
    tempo para as execuções: 10,100,1.000,10.000 foi igual a 0.0
    100.000, para execuções distintas foi obtido os seguintes tempos: 0.01 e 0.02
    1.000.000 foi obtido um tempo de 0.22
  Crescente:
    tempo para as execuções: 10,100,1.000 foi igual a 0.0
    10.000 para execuções distintas foi obtido os seguintes tempos: 0.23 e 0.25
    para execuções dos seguintes números: 100.000 e 1.000.000 no Windons não executou corretamente (não conseguiu calcular o tempo), entretanto
    acredito estar certo a maneira implementada, pois para os valores aleatórios todos executaram corretamente.
  Decrescente:
    tempo para as execuções: 10,100,1.000 foi igual a 0.0
    10.000 para execuções distintas foi obtido os seguintes tempos: 0.17 e 0.20
    para execuções dos seguintes números: 100.000 e 1.000.000 no Windons não executou corretamente (não conseguiu calcular o tempo), entretanto
    acredito estar certo a maneira implementada, pois para os valores aleatórios todos executaram corretamente.
*/

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (vetor[i] > vetor[i+1]) {
       return 0;
    }
  }
  return 1;
}

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

    return (i+1);
}

void QuickSort (int *vetor, int esq, int dir) {
    if (esq < dir){
        int q = particione(vetor, esq, dir);
        QuickSort(vetor, esq, q-1);
        QuickSort(vetor, q+1, dir);
    }
}

/*Função principal.*/
int main (int argc, char *argv[]) {
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int i;
   int tamanho = 10;
   int *vetor = (int *)malloc(tamanho * sizeof(int));
   for (i = 0; i < tamanho; i++) {
      vetor[i] = rand() % (tamanho+1); //aleatorio
      //vetor[i] = i;  //crescente
      //vetor[i] = tamanho - i;   //decrescente
   }
   Imprimir (vetor, tamanho);
   start = clock();
   QuickSort (vetor, 0, tamanho-1);
   end = clock();
   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;

   if (!Verifica_Ordenacao(vetor, tamanho)) {
      printf("Erro: a ordenacao nao esta correta!\n");
   }
   Imprimir (vetor, tamanho);
   printf("Tempo de execucao (Quick-Sort): %f\n", elapsed_time);
   free (vetor);
   return 0;
}
