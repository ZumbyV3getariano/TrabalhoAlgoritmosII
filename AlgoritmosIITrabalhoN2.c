
// Trabalho N2, Algoritmos II(2), Nome: GABRIEL SOARES FRAGOSO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 100

// Ramdomizador
int random(int random) {
    return rand() % random;
}

//Função Para Nao Existir Cheques Iguais
int existe(int tamanhoOrdem, int vetor[], int valor)
{
    for (int i = 0; i < tamanhoOrdem; i++) {
        if (vetor[i] == valor) {
            return 0; //Já Existe
        }
    }
    return 1; //Não Existe
}

int main() {

    int cheques[TAMANHO];
    int chequesOrganizados[TAMANHO];

    srand((unsigned)time(NULL));

    //Cria varios cheque em ordem aleatoria usando DoWhile e Random
    int tamanhoFeito = 0;
    do{
        int numAleatorio = random(TAMANHO) + 1;
        if(existe(tamanhoFeito, cheques, numAleatorio) == 1)
        {
            cheques[tamanhoFeito] = numAleatorio;
            tamanhoFeito++;
        }
    }while (tamanhoFeito < TAMANHO);

    // Mostra Os Cheques Antes De Ordena-Los
    printf("Cheques embaralhados:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", cheques[i]);
    }
    printf("\n\n");

    // Coloca os Cheques em Ordem Usando a Mesma Logica Do Embaralhamento
    tamanhoFeito = 0;
    for (int i = 1; i <= TAMANHO; i++) {
        if (existe(tamanhoFeito, chequesOrganizados, i) == 1) {
            chequesOrganizados[tamanhoFeito] = i;
            tamanhoFeito++;
        }
    }

    // Mostra Os Cheques Em Ordem
    printf("Cheques Ordenados:\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", chequesOrganizados[i]);
    }

    printf("\n\n");

    system("pause");

    return 0;
}
