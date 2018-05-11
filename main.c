#include <stdio.h>
#include <stdlib.h>

/*Problema do troco (Algoritmo Guloso)

Trabalho para obtenção de nota da disciplina de Projeto e analise de Algoritmo
*/
int calculaQuantidadeMoedas(int *vetorMoedas, int valorTroco, int tamanhoVetorMoedas){
    int quantidadeMoedas = 0, i;

    for(i = tamanhoVetorMoedas - 1; i >= 0; i--)
	{
		int aux_moedas = valorTroco / vetorMoedas[i];
		valorTroco -= aux_moedas * vetorMoedas[i];
		quantidadeMoedas += aux_moedas;
	}
	return quantidadeMoedas;
}

int main()
{
    int tamanhoVetorMoedas, valorTroco, *vetorMoedas,i,j;

    printf("-------------------Problema do Troco-------------------\n\nDigite a quantidade de tipos de moedas:\n");
    scanf("%d",&tamanhoVetorMoedas);
    vetorMoedas = (int*) malloc(tamanhoVetorMoedas* sizeof(int));

    //Ler os Valores dos tipos das moedas
    printf("\nDigite os tipos de moedas obedecendo a quantidade que voce solicitou:\n\nEx: 1 2 5 10 20:\n");
    for(i=0; i<tamanhoVetorMoedas; i++){
        scanf("%d",&vetorMoedas[i]);
    }

    //Imprimir a Lista dos tipos de moedas
    printf("\nSeus tipos de moedas para o calculo de quantidade de moedas sao {");
    for(i=0; i<tamanhoVetorMoedas; i++){
        if(i == tamanhoVetorMoedas - 1)
            printf("%d}",vetorMoedas[i]);
        else
            printf("%d,", vetorMoedas[i]);
    }

    printf("\n\nDigite o seu Troco para efetuar o calculo\n");
    scanf("%d",&valorTroco);

    printf("\nQuantidade de Moedas para o troco %d", calculaQuantidadeMoedas(vetorMoedas, valorTroco, tamanhoVetorMoedas));

    return 0;
}
