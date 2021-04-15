#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Ordena1 (int *vetor, int tamanho) {
    int temp = 0;
    for(int j = 0; j < tamanho-1; j++){
        if (vetor[j] > vetor[j+1]){
            int aux;
            aux = vetor[j+1];
            vetor[j+1] = vetor[j];
            vetor[j] = aux;
            temp = 1;
        }
        if (temp != 0)
        {
            Ordena1(vetor, tamanho-1);
        }
    }

}


void Ordena2 (int *vetor, int tamanho) {

    int aux = 0;
    for(int j = tamanho; j >= 0; j--){
        while(vetor[j] < vetor[j-1]){
            int temp;
            temp = vetor[j-1];
            vetor[j-1] = vetor[j];
            vetor[j] = temp;

            aux = 1;
        }
        if (aux != 0)
        {
            Ordena2(vetor, tamanho);
        }
    }
}

void Ordena3 (int *vetor, int tamanho) {
    if (tamanho == 1){
        return;
    }

    Ordena3(vetor, tamanho-1);
    int chave = vetor[tamanho-1];
    int j = tamanho - 2;
    while (j >= 0 && vetor[j] > chave){
        vetor[j+1] = vetor[j];
        j--;
    }
    vetor[j+1] = chave;
}

void Imprimir (int *A, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d, ", A[i]);
  }
  printf("\n");
}

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *A, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (A[i] > A[i+1]) {
       return 0;
    }
  }
  return 1;
}


int main () {

  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));

  int i;

  int tamanho = 10;

  int *v1 = (int *)malloc(tamanho * sizeof(int));
  int *v2 = (int *)malloc(tamanho * sizeof(int));
  int *v3 = (int *)malloc(tamanho * sizeof(int));

  for (i = 0; i < tamanho; i++) {
     v1[i] = rand() % (tamanho+1);
     v2[i] = rand() % (tamanho+1);
     v3[i] = rand() % (tamanho+1);
  }

  start = clock();
  Imprimir(v1, tamanho);
  Ordena1 (v1, tamanho);
  Imprimir(v1, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execucao (ordenacao 1): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v1, tamanho)) {
     printf("Erro: a ordenacao 1 nao esta correta!\n");
  }

  start = clock();
  Imprimir(v2, tamanho);
  Ordena2 (v2, tamanho);
  Imprimir(v2, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execucao (ordenacao 2): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v2, tamanho)) {
     printf("Erro: a ordenacao 2 nao esta correta!\n");
  }

  start = clock();
  Imprimir(v3, tamanho);
  Ordena3 (v3, tamanho);
  Imprimir(v3, tamanho);
  end = clock();
  elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
  printf("Tempo de execucao (ordenacao 3): %.2f\n", elapsed_time);
  if (!Verifica_Ordenacao(v3, tamanho)) {
     printf("Erro: a ordenacao 3 nao esta correta!\n");
  }

  free (v1);
  free (v2);
  free (v3);

  return 0;
}

