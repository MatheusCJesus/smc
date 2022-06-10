#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char data[12];
    int dia = 0;
    int mes = 0;
    int ano = 0;
    char *meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outrubro", "Novembro", "Dezembro"};
    
    printf("Digite uma data no formato DD/MM/AAAA: ");
    scanf("%2d/%2d/%4d", &dia, &mes, &ano);

    printf("%d de %s de %d\n", dia, meses[mes], ano);

    return 0;
}
