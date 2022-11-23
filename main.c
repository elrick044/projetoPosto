#include <stdbool.h>
#include <stdio.h>

#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define NONE "\033[0m"

void delay(unsigned int secs) {
    unsigned int end = time(0) + secs;
    while (time(0) < end)
        ;
}

void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

int main(void) {

    int tamanho;
    float preco;
    int numCarros = 0;
    int carrosAtendidos = 0;
    int qtdLitros = 200;

    printf("Autor: Erick G. da Silva\n");
    printf("Este é um programa para melhorar o processo de gerenciamento das "
           "informações de um posto de gasolina\n");

    printf("\n---------------\n\n");

    while (true) {
        printf("Digite o valor do combustivel: \n");
        scanf("%f", &preco);
        if (preco > 0) {
            break;
        } else {
            printf("%sDigite um precço maior que zero%s\n", C_RED, NONE);
        }
    }

    while (true) {
        printf("Digite o tamanho da fila: \n");
        scanf("%i", &tamanho);
        if (tamanho > 0) {
            break;
        } else {
            printf("%sDigite um tamanho maior que zero%s\n", C_RED, NONE);
        }
    }

    //---------------------------------------\\

    int op;
    char op2 = 'z';
    system("clear");
    while (true) {
        printf("1 - Adicionar um carro na fila\n");
        printf("2 - Abastecimento\n");
        printf("3 - Exibir carros na fila de espera\n");
        printf("4 - Relatórios\n");
        printf("%s5 - Encerrar %s\n", C_RED, NONE);

        scanf(" %i", &op);

        if (op == 5) {
            system("clear");
            printf("%sFinalizando...%s", C_RED, NONE);
            break;
        }

        switch (op) {
            case 1:
                system("clear");
                if (numCarros < tamanho) {
                    printf("%sCarro adicionado%s\n", C_GREEN, NONE);
                    numCarros++;
                    printf("Número de carros: %i", numCarros);
                } else {
                    printf("%sA fila está cheia%s\n", C_RED, NONE);
                }
                break;
            case 2:
                system("clear");
                if (numCarros > 0) {
                    printf("%sInforme a quantidade de combustivel: %s\n", C_YELLOW, NONE);
                    int aux;
                    scanf("%i", &aux);
                    if (aux > qtdLitros) {
                        printf("%sNão temos todo esse combustivel no nosso tanque%s\n", C_RED,
                               NONE);
                    } else {
                        printf("%sCarro abastecido%s\n", C_GREEN, NONE);
                        qtdLitros -= aux;
                        numCarros--;
                        carrosAtendidos++;
                    }

                } else {
                    printf("%sNão há carros na fila%s\n", C_RED, NONE);
                }

                break;
            case 3:
                system("clear");
                printf("%sCarros exibidos%s\n", C_GREEN, NONE);
                break;
            case 4:
                system("clear");
                while (true) {
                    // printf("Digite a opação dos relatórios: \n");
                    printf("a - Quantidade de litros vendida;\n");
                    printf("b - Valor total arrecadado com as vendas;\n");
                    printf("c - Quantidade de carros atendidos;\n");
                    printf("d - Quantidade de combustível restante no tanque;\n");
                    printf("e - Gerar arquivo para impressão (com todas as informações de "
                           "A, B, C e D);\n");
                    printf("%sf - voltar ao menu anterior.%s\n", C_YELLOW, NONE);
                    // op2 = getchar();
                    flush_in();
                    scanf("%c", &op2);
                    if (op2 == 'f') {
                        printf("%sVoltando ao menu inicial...%s\n", C_YELLOW, NONE);
                        break;
                    }
                    switch (op2) {
                        case 'a':
                            printf("%sForam vendidos %i litros %s\n", C_YELLOW, 200 - qtdLitros,
                                   NONE);
                            // Sleep(1000);
                            delay(2);
                            system("clear");
                            break;
                        case 'b':
                            printf("%sForam arrecadados R$%.2f, com as vendas%s\n", C_YELLOW,
                                   (200 - qtdLitros) * preco, NONE);
                            delay(2);
                            system("clear");
                            break;
                        case 'c':
                            printf("%sForam atendidos %i carros%s\n", C_YELLOW, carrosAtendidos,
                                   NONE);
                            delay(2);
                            system("clear");
                            break;
                        case 'd':
                            printf("%sAinda resta %i litros de combustivel no tanque.%s\n4",
                                   C_YELLOW, qtdLitros, NONE);
                            delay(2);
                            system("clear");
                            break;
                            delay(2);
                            system("clear");
                        case 'e':
                            printf("%sRelatório e%s", C_YELLOW, NONE);
                            break;
                    }
                    break;
                }
        }
    }
    return 0;
}