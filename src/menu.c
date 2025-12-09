#include "../include/menu.h"
#include <stdio.h>
#include <stdlib.h>

// Função que mostra o menu e retorna a opção escolhida pelo usuário
int show_Menu()
{
    char temp[10]; // Buffer de texto
    int opc;

    printf("|=======================================================|\n");
    printf("|                   AGENDA DE CONTATO                   |\n");
    printf("|=======================================================|\n");
    printf("|               [1]      LISTAR                         |\n");
    printf("|               [2]     PESQUISAR                       |\n");
    printf("|               [3]     ADICIONAR                       |\n");
    printf("|               [4]      EXCLUIR                        |\n");
    printf("|               [5]       SAIR                          |\n");
    printf("|=======================================================|\n");
    printf("|               DIGITE O NUMERO DESEJADO                |\n");
    printf("|=======================================================|\n");

    printf("|           : ");
    fgets(temp, 10, stdin);
    opc = atoi(temp);

    return opc;
}