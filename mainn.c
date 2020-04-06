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

    for (;*palavra;palavra++)
    {
        push(p,*palavra);
    }

    while(!empty(p))
    {
        for(;*palavra;palavra++)
            if(*palavra == pop(p))
                continue;
            else
                return 0;
    }
    free_stack(p);

    return 1;
}
