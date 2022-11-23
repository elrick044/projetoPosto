#include <stdio.h>
#include <stdbool.h>

void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

int main(void) {

    int tamanho;
    float preco;

    printf("Autor: Erick G. da Silva\n");
    printf("Este é um programa para melhorar o processo de gerenciamento das informações de um posto de gasolina\n");

    printf("Digite o valor do combustivel\n");
    scanf("%f", &preco);

    printf("Digite o tamanho da fila\n");
    scanf("%i", &tamanho);

    //---------------------------------------\\

    int op;
    char op2 = 'z';

    while(true){
        printf("1 - Adicionar um carro na fila\n");
        printf("2 - Abastecimento\n");
        printf("3 - Exibir carros na fila de espera\n");
        printf("4 - Relatórios\n");
        printf("5 - Encerrar \n");

        scanf(" %i", &op);

        if(op == 5){
            printf("Finalizando...");
            break;
        }

        switch(op){
            case 1:
                printf("Carro adicionado\n");
                break;
            case 2:
                printf("Carro abastecido\n");
                break;
            case 3:
                printf("Carros exibidos\n");
                break;
            case 4:
                while(true){
                    //printf("Digite a opação dos relatórios: \n");
                    printf("a - Quantidade de litros vendida;\n");
                    printf("b - Valor total arrecadado com as vendas;\n");
                    printf("c - Quantidade de carros atendidos;\n");
                    printf("d - Quantidade de combustível restante no tanque;\n");
                    printf("e - Gerar arquivo para impressão (com todas as informações de A, B, C e D);\n");
                    printf("f - voltar ao menu anterior.\n");
                    //op2 = getchar();
                    flush_in();
                    scanf("%c", &op2);
                    if(op2 == 'f'){
                        printf("Voltando ao menu inicial...\n");
                        break;
                    }
                    switch(op2){
                        case 'a':
                            printf("Relatório a");
                            break;
                        case 'b':
                            printf("Relatório b");
                            break;
                        case 'c':
                            printf("Relatório c");
                            break;
                        case 'd':
                            printf("Relatório d");
                            break;
                        case 'e':
                            printf("Relatório e");
                            break;
                        case 'f':
                            printf("Relatório f");
                            break;
                    }
                }
                break;
        }
    }
    return 0;
}