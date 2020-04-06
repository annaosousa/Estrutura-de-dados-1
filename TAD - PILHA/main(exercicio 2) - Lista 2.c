//#include <iostream>
#include <string.h>
#include "Pilha.h"

int main()
{
    char *palavra = "anna";

    printf(palindromo(palavra)?"E palindromo":"Nao e palindromo");

	return 0;
}

int palindromo(const char* palavra)
{
    Stack* p = create_stack (strlen(palavra));

    int i=0;

    for (;*palavra;palavra++)
    {
        push(p,*palavra);
    }

    while(!empty(p))
    {
        for(;*palavra;palavra++)
            if(*palavra == pop(p))
                i++;
            else
                return 0;
    }
    free_stack(p);

    return 1;
}
