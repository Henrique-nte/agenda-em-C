// PROJETO AGENDA EM C
// ESTUDANTES: HENRIQUE S., YAGO, YURI, GABRIEL FLÔR, EMANOEL.

// CABEÇALHOS
#include "../include/main.h"
#include "../include/menu.h"
#include "../include/contacts.h"
#include "../include/validators.h"
#include "../include/delete_Contact_Logic.h"

// BIBLIOTECAS UTILIZADAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Biblioteca de string
#include <stdbool.h> // Permite tipos booleanos
#include <unistd.h>  // Linux (Windows usa <windows.h>)

extern char clear_Command[]; // "clear" Para linux e "cls" para windows

// Função de lógica para deletar contato
void delete_Contact_Logic(Contato *contatos)
{
    char name[50];
    int exist;

    do
    {

        printf("|=======================================================|\n");
        printf("|                   EXCLUIR CONTATO                     |\n");
        printf("|=======================================================|\n\n");

        printf("NOME: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // remove o \n ao final

        exist = contact_Exists(name, contatos);

        if (!exist)
        {
            system(clear_Command);
            printf("|=======================================================|\n");
            printf("|          ERRO: CONTATO NAO ENCONTRADO                 |\n");
            printf("|=======================================================|\n\n");
            return;
        }

    } while (exist == 0);

    // Quando existe, efetua a exclusão
    delete_Contact(name, contatos);
}
