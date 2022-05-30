#include <stdio.h>

int main(int argc, char const *argv[])
{
    int lista[] = {
                    6, 7, 8, 9, 8, 7, 8, 9, 8, 9, 7, 8, 9, 5, 9, 8, 7, 8, 7, 8, 6, 7, 8, 9, 3, 9,
                    8, 7, 8, 7, 7, 8, 9, 8, 9, 8, 9, 7, 8, 9, 6, 7, 8, 7, 8, 7, 9, 8, 9, 2, 7, 8,
                    9, 8, 9, 8, 9, 7, 5, 3, 5, 6, 7, 2, 5, 3, 9, 4, 6, 4, 7, 8, 9, 6, 8, 7, 8, 9,
                    7, 8, 7, 4, 4, 2, 5, 3, 8, 7, 5, 6, 4, 5, 6, 1, 6, 5, 7, 8, 7
                };
    int frequencias[10] = {0,0,0,0,0,0,0,0,0,0};
    float soma = 0.0;

    for (size_t i = 0; i < 99; i++)
    {
        soma = soma + lista[i];

        switch (lista[i])
        {
        case 0:
            frequencias[0]++;
            break;
        case 1:
            frequencias[1]++;
            break;
        case 2:
            frequencias[2]++;
            break;
        case 3:
            frequencias[3]++;
            break;
        case 4:
            frequencias[4]++;
            break;
        case 5:
            frequencias[5]++;
            break;
        case 6:
            frequencias[6]++;
            break;
        case 7:
            frequencias[7]++;
            break;
        case 8:
            frequencias[8]++;
            break;
        case 9:
            frequencias[9]++;
            break;
        
        default:
            break;
        }
    }

    float media = 0.0;
    
    media = soma / 99;

    printf("A média dos dados é: %f\n", media);

    for (size_t i = 0; i < 10; i++)
    {
        if (frequencias[i] != 0)
        {
            printf("Frequência do número %d é de: %d\n", i, frequencias[i]);
        }
    }
    
    
    return 0;
}
