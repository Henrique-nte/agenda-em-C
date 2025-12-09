// PROJETO AGENDA EM C
// ESTUDANTES: HENRIQUE S., YAGO,YURI, GABRIEL FLÔR, EMANOEl.

// CABEÇALHOS
#include "../include/main.h"
#include "../include/menu.h"
#include "../include/contacts.h"
#include "../include/validators.h"
#include "../include/add_Contact_Logic.h"
#include "../include/delete_Contact_Logic.h"

// BIBLIOTECAS UTILIZADAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //Biblioteca de string
#include <stdbool.h> //Permite tipos booleano
#include <unistd.h>  // #include <windows.h> //No windows

extern char clear_Command[]; // "clear" Para linux e "cls" para windows
extern int used;

void runApp()
{
    Contato contatos[QTY];
    char name[50];
    int opc;
    bool ok;

    while (1)
    {
        opc = show_Menu();

        switch (opc)
        {
        case 1:
            if (used == 0) // Array vazio
            {
                system(clear_Command);
                printf("|=======================================================|\n");
                printf("|                     LISTA VAZIA!!                     |\n");
                printf("|=======================================================|\n\n");
                break;
            }
            system(clear_Command);
            show_Contacts(contatos);
            break;
        case 2:
            if (used == 0) // Array vazio
            {
                system(clear_Command);
                printf("|=======================================================|\n");
                printf("|                     LISTA VAZIA!!                     |\n");
                printf("|=======================================================|\n\n");
                break;
            }

            system(clear_Command);
            printf("|=======================================================|\n");
            printf("|                   DIGITE O CONTATO                    |\n");
            printf("|=======================================================|\n\n");
            printf("Nome: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0'; // remove o \n

            find_contact_by_name(name, contatos);

            break;
        case 3:
            system(clear_Command);
            add_Contact_Logic(contatos);
            break;
        case 4:

            if (used == 0) // Array vazio
            {
                system(clear_Command);
                printf("|=======================================================|\n");
                printf("|                     LISTA VAZIA!!                     |\n");
                printf("|=======================================================|\n\n");
                break;
            }

            system(clear_Command);
            delete_Contact_Logic(contatos);
            break;

        case 5:
            system(clear_Command);
            printf("|====================================|\n");
            printf("|              ATE LOGO!!            |\n");
            printf("|====================================|\n");
            return;

        default:
            system(clear_Command);
            printf("|=======================================================|\n");
            printf("|                    OPCAO INVALIDA!!                   |\n");
            printf("|=======================================================|\n\n");
            break;
        }
    }
}

int main()
{
    runApp();
    return 0;
}
