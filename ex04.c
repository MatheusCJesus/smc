#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char data[10];
    int dia = 0;
    int mes = 0;
    int ano = 0;
    char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outrubro", "Novembro", "Dezembro"};
    
    printf("Digite uma data no formato DD/MM/AAAA: ");
    fgets(data, 10, stdin);

    // Obter o dia, mes e ano
    char d[2], m[2], a[4];
    for (size_t i = 0; i < 10; i++)
    {
        if (i <= 1)
        {
            d[i] = data[i];
        } else if (i >= 3 && i <= 4)
        {
            m[i-3] = data[i];
        } else if (i > 5)
        {
            a[i-6] = data[i];
        }
    }

    dia = atoi(d);
    mes = atoi(m);
    ano = atoi(a);
    printf("%d de %d de %d", dia, mes, ano);

    return 0;
}
