
#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    
    char string[100];
    char MAIUSCULAS[100];
    char minusculas[100];

    printf("Digite até 100 caracteres: ");
    fgets(string, 100, stdin);

    printf("%s\n", string);

    for (size_t i = 0; i < 100; i++)
    {
        MAIUSCULAS[i] = toupper(string[i]);
        minusculas[i] = tolower(string[i]);
    }
    
    printf("String com todas as letras MAIUSCULAS: %s", MAIUSCULAS);
    printf("String com todas as letras minusculas: %s", minusculas);
    
    return 0;
}
