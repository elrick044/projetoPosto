#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_YELLOW "\033[33m"
#define NONE "\033[0m"

struct Tcarro{
    char modelo[255];
    char marca[255];
    int ano;
    int portas;
    int eletrico;
};

void delay(unsigned int secs) {
    unsigned int end = time(0) + secs;
    while (time(0) < end);
}

void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

void tirarCarroDaFila(struct Tcarro fila[], int tamanho){
    for(int i = 0; i < tamanho - 1; i++){
        fila[i] = fila[i+1];
    }
}

int abastecer(int numCarros, int qtdLitros, int eletrico){
    int aux;
    int nkwh;
    system("clear");
    if (numCarros > 0) {
        if (eletrico == 1){

            printf("Digite o número de KWh: ");
            scanf("%i", &nkwh);
            printf("%sCarro abastecido%s\n", C_GREEN, NONE);

        } else {

            printf("%sInforme a quantidade de combustivel: %s\n", C_YELLOW, NONE);

            scanf("%i", &aux);
            if (aux > qtdLitros) {
                printf("%sNão temos todo esse combustivel no nosso tanque%s\n", C_RED,
                       NONE);
            } else {
                printf("%sCarro abastecido%s\n", C_GREEN, NONE);
            }
        }

    } else {
        printf("%sNão há carros na fila%s\n", C_RED, NONE);
    }

    return aux;
}

struct Tcarro lerCarro(){
    struct Tcarro aux;
    printf("Digite o modelo do carro: \n");
    scanf("%s", &aux.modelo);
    printf("Digite a marca do carro: \n");
    scanf("%s", &aux.marca);
    printf("Digite o ano do carro: \n");
    scanf("%i", &aux.ano);
    flush_in();
    printf("Digite o número de portas do carro: \n");
    scanf("%d", &aux.portas);
    printf("É elétrico? (1 = sim; 0 = não): \n");
    scanf("%i", &aux.eletrico);

    return aux;
}

void imprimirCarros(struct Tcarro carros[], int tamanho){
    for (int i = 0; i < tamanho; ++i) {
        if(carros[i].ano == 0){
            if(i == 0){
                printf("%sNão há carros na fila%s\n", C_GREEN, NONE);
            }
            break;
        }else{
            printf("Modelo: %s\n", carros[i].modelo);
            printf("Marca: %s\n", carros[i].marca);
            printf("Ano: %i\n", carros[i].ano);
            printf("Portas: %i\n\n", carros[i].portas);
        }

    }
}

int main(void) {

    int tamanho = 10;
    float preco;
    float precoKWh;
    int numCarros = 0;
    int qtdLitros = 200;
    int carrosAtendidos = 0;

    int litrosAbastecidos;//refere-se a quantidade de litros abastecidos em cada vez, para subtrair do totoal;

    struct Tcarro fila[tamanho];
    struct Tcarro atendidos[tamanho];

    for (int i = 0; i < tamanho; ++i) {
        fila[i].ano = 0;
        atendidos[i].ano = 0;
    }

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
        printf("Digite o valor por KWh: \n");
        scanf("%f", &precoKWh);
        if (precoKWh > 0) {
            break;
        } else {
            printf("%sDigite um precço maior que zero%s\n", C_RED, NONE);
        }
    }

    /*
    while (true) {
        printf("Digite o tamanho da fila: \n");
        scanf("%i", &tamanho);
        if (tamanho > 0) {
            break;
        } else {
            printf("%sDigite um tamanho maior que zero%s\n", C_RED, NONE);
        }
    }
    */



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
                    fila[numCarros] = lerCarro();
                    numCarros++;
                    printf("Número de carros: %i\n", numCarros);
                    delay(2);
                    system("clear");
                } else {
                    printf("%sA fila está cheia%s\n", C_RED, NONE);
                }
                break;
            case 2:
                litrosAbastecidos = abastecer(numCarros, qtdLitros, fila[carrosAtendidos].eletrico);
                qtdLitros = qtdLitros - litrosAbastecidos;
                numCarros--;

                atendidos[carrosAtendidos] = fila[0];

                tirarCarroDaFila(fila,tamanho);

                carrosAtendidos++;
                break;
            case 3:
                system("clear");
                imprimirCarros(fila,tamanho);
                printf("%sCarros exibidos%s\n", C_GREEN, NONE);
                delay(5);
                system("clear");
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