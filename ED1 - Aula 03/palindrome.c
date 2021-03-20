#include <string.h>
#include "Pilha.h"

/*Exercicio

Escreva um programa solicite ao usu�rio uma sequ�ncia de caracteres e realize
as seguintes opera��es usando uma pilha:
a) Imprimir o texto na ordem inversa;
b) Verificar se o texto � um pal�ndromo, ou seja, se a string � escrita da
mesma maneira de frente para tr�s e de tr�s para frente.

**implementa��o do exerc�cio proposto e o exerc�cio da lista encontram-se em pilha.c**

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
