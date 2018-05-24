#include <stdio.h>
#include <stdlib.h>

/*Problema do troco (Algoritmo Guloso)

Trabalho para obtenção de nota da disciplina de Projeto e analise de Algoritmo
*/

/*Essa função recebe 3 parâmetros que são: um vetor de moedas diponibilizadas pelo usuário o valor do troco a ser calculado
e o tamanho do vetor que foi lido pelo usuario.

Após receber os dados no parâmetro a função vai fazer uma divisão do valor do troco pela maior moeda diponível para saber a
quantidade de moedas, depois será adicionados o valor em um contador de moedas, depois é subtraido do valor do troco a quantidadecde de
moedas usadas assim passando para a próxima moeda menor seguindo o laço de repetição chegando na menor moeda possivel para o troco.
Ao final o contador de moedas é o resultado esperado*/
int calculaQuantidadeMoedas(int *vetorMoedas, int valorTroco, int tamanhoVetorMoedas){
    int quantidadeMoedas = 0, i;

    for(i = tamanhoVetorMoedas - 1; i >= 0; i--)
	{
	    //Divisão para saber a quantidade de moedas no momento
		int aux_moedas = valorTroco / vetorMoedas[i];

		if(aux_moedas != 0)
            printf("%d moeda(s) de %d\n", aux_moedas, vetorMoedas[i]);

		//Atualização do valor do troco após usar a moeda no momento
		valorTroco -= aux_moedas * vetorMoedas[i];

		//Contador de moedas
		quantidadeMoedas += aux_moedas;
	}
	return quantidadeMoedas;
}

int main()
{
    //variável vetorMoedas usado para guardar os tipos de moedas
    //variável valorTroco usado para guardar o valor lido do Troco a ser calculado
    // variável tamanhoVetorMoedas usado para alocar o vetor com as quantidades de moedas lida pelo usuário
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
