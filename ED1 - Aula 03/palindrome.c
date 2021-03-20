#include <string.h>
#include "Pilha.h"

/*Exercicio

Escreva um programa solicite ao usuário uma sequência de caracteres e realize
as seguintes operações usando uma pilha:
a) Imprimir o texto na ordem inversa;
b) Verificar se o texto é um palíndromo, ou seja, se a string é escrita da
mesma maneira de frente para trás e de trás para frente.

**implementação do exercício proposto e o exercício da lista encontram-se em pilha.c**

https://www.ic.unicamp.br/~ra144681/courses/mc202/slides/files/Lista02-Listas_Pilhas_Filas.pdf
*/
int main ()
{
    char *palavra[150];
    int i = 0;
    printf("Digite um texto/palavra para verificar se eh ou nao palindrome:");
    scanf("%s", &palavra);

    printf(verifica_palindromo(palavra)?"\nE palindromo":"\nNao e palindromo");

}
