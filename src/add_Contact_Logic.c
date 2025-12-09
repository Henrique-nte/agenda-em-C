// CABEÇALHOS
#include "../include/contacts.h"
#include "../include/validators.h"
#include "../include/add_Contact_Logic.h"
#include "../include/main.h"

// BIBLIOTECAS UTILIZADAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //Biblioteca de string
#include <stdbool.h> //Permite tipos booleano

extern char clear_Command[];

// Repete até o usuário digitar um contato que não existe
void add_Contact_Logic(Contato *contatos)
{
    char name[50], phone[17];
    int opc, exist = true;
    bool ok = false;

    while (exist != false) // Enquanto oque ele digitar ja estiver no array
    {
        do // Repete até ele digitar um nome válido
        {
            printf("|=======================================================|\n");
            printf("|                   ADICIONAR CONTATO                   |\n");
            printf("|=======================================================|\n\n");
            printf("NOME: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0'; // remove o \n

            if (validate_Name(name))
            {
                ok = true;
                system(clear_Command);
            }

            if (!validate_Name(name))
            {
                system(clear_Command);
                printf("|=======================================================|\n");
                printf("|                 ERRO: NOME INVALIDO!!                 |\n");
                printf("|=======================================================|\n\n");
            }
        } while (ok != true);

        exist = contact_Exists(name, contatos);
        if (exist)
        {
            system(clear_Command);
            printf("|=======================================================|\n");
            printf("|             ERRO: CONTATO JA EXISTE!                  |\n");
            printf("|=======================================================|\n\n");
            return;
        }
    }

    ok = false; // reseta a variavel ok

    while (ok != true) // Repete até ele digitar um numero válido
    {
        printf("NOME: %s\n", name);
        printf("TELEFONE: ");
        fgets(phone, sizeof(phone), stdin);
        phone[strcspn(phone, "\n")] = '\0'; // remove o \n

        if (validate_Phone(phone))
            ok = true;

        if (!validate_Phone(phone))
        {
            system(clear_Command);
            printf("|=======================================================|\n");
            printf("|                ERRO: NUMERO INVALIDO                  |\n");
            printf("|=======================================================|\n\n");
        }
    }

    // Adiciona no array
    add_Contact(name, phone, contatos);
}
