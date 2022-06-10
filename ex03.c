#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct 
{
    char *nome;
    float faturamento;
    float salario;
    int faixa_salarial;

} Vendedor;

int aleatorio(int a,int b);
float calcula_salario(float faturamento);

char nomes[10][10] = {
    "Matheus",
    "Carlos",
    "João",
    "Joaquim",
    "Ana",
    "Deborah",
    "Ahmad",
    "Adriano",
    "Hiro",
    "Rudolf"
};

int faixas[] = {0, 0, 0, 0, 0, 0, 0, 0};


int main(int argc, char const *argv[])
{

    srand(time(0));

    Vendedor vendedor[10];

    for (int i=0; i<10; i++) 
    {

        int r = aleatorio(1, 13);

        vendedor[i].faturamento = r*1000;
        vendedor[i].nome = nomes[i];
        vendedor[i].salario = calcula_salario(vendedor[i].faturamento);

        if (vendedor[i].salario >= 500.00 && vendedor[i].salario <= 599.00)
        {
            vendedor[i].faixa_salarial = 1;
            faixas[0] += 1;
        } else if (vendedor[i].salario >= 600.00 && vendedor[i].salario <= 699.00)
        {
            vendedor[i].faixa_salarial = 2;
            faixas[1] += 1;
        } else if (vendedor[i].salario >= 700.00 && vendedor[i].salario <= 799.00)
        {
            vendedor[i].faixa_salarial = 3;
            faixas[2] += 1;
        } else if (vendedor[i].salario >= 800.00 && vendedor[i].salario <= 899.00)
        {
            vendedor[i].faixa_salarial = 4;
            faixas[3] += 1;
        } else if (vendedor[i].salario >= 900.00 && vendedor[i].salario <= 999.00)
        {
            vendedor[i].faixa_salarial = 5;
            faixas[4] += 1;
        } else if (vendedor[i].salario >= 1000.00 && vendedor[i].salario <= 1199.00)
        {
            vendedor[i].faixa_salarial = 6;
            faixas[5] += 1;
        } else if (vendedor[i].salario >= 1200.00 && vendedor[i].salario <= 1299.00)
        {
            vendedor[i].faixa_salarial = 7;
            faixas[6] += 1;
        } else if (vendedor[i].salario >= 1300.00)
        {
            vendedor[i].faixa_salarial = 8;
            faixas[7] += 1;
        }
        
    }
    

    printf(" **** FAIXAS SALARIAIS **** \n");
    printf(" R$500,00 a R$599,00   -> %d vendedores\n", faixas[0]);
    printf(" R$600,00 a R$699,00   -> %d vendedores\n", faixas[1]);
    printf(" R$700,00 a R$799,00   -> %d vendedores\n", faixas[2]);
    printf(" R$800,00 a R$899,00   -> %d vendedores\n", faixas[3]);
    printf(" R$900,00 a R$999,00   -> %d vendedores\n", faixas[4]);
    printf(" R$1000,00 a R$1199,00 -> %d vendedores\n", faixas[5]);
    printf(" R$1200,00 a R$1299,00 -> %d vendedores\n", faixas[6]);
    printf(" R$1300,00             -> %d vendedores\n", faixas[7]);


    return 0;
}

float calcula_salario(float faturamento) 
{
    return 500.0 + faturamento*0.09;
}

int aleatorio(int a,int b)  
{
    return (a+rand()%(b-a+1));
}
