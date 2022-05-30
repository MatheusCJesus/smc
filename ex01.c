
#include <stdio.h>

// ### Exercício 1 ### //
// ###  Automóvel  ### //

float calcula_distancia(float tempo, float velocidade);
float consumo_combustivel(float distancia, float consumo_medio);

int main(int argc, char const *argv[])
{
    float con_med;
    float tgasto;
    float vm;

    printf("Tempo da viagem: ");
    scanf("%f", &tgasto);

    printf("Velocidade media: ");
    scanf("%f", &vm);

    printf("Consumo medio: ");
    scanf("%f", &con_med);

    float distancia = calcula_distancia(tgasto, vm);
    float consumo = consumo_combustivel(distancia, con_med);

    printf("Distancia percorrida é igual a: %.2f", distancia);
    printf(" [Km]\n");
    printf("O consumo total é igual a: %.2f", consumo);
    printf(" [L]\n");
    
    return 0;
}

float calcula_distancia(float tempo, float velociade) {

    float dist_total = 0.0;

    return dist_total = velociade * tempo;

}

float consumo_combustivel(float distancia, float consumo_medio) {

    float consumo_total = 0.0;

    return consumo_total = distancia / consumo_medio;

}
