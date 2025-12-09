#include "../include/contacts.h"
#include "../include/menu.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h> // #include <windows.h> //No windows
#include <stdlib.h>
#include "main.h"
extern int used;
extern char clear_Command[]; // "clear" Para linux e "cls" para windows

// Mostrar lista de Contatos
void show_Contacts(Contato *c)
{
    system(clear_Command);

    printf("|=======================================================|\n");
    printf("|                  LISTA DE CONTATOS                    |\n");
    printf("|=======================================================|\n\n");

    for (int i = 0; i < used; i++)
    {
        printf("|=======================================================|\n");
        printf("|                     CONTATO %i                         |\n", i + 1);
        printf("|-------------------------------------------------------|\n");
        printf("| Nome: %-48s|\n", c[i].name);
        printf("| Telefone: %-44s|\n", c[i].phone);
        printf("|=======================================================|\n\n");
    }
}

// Função que verifica se contato ja existe no array
int contact_Exists(char name[], Contato *c)
{

    // Verifica se já existe no array
    for (int i = 0; i < used; i++)
    {
        if (strcmp(c[i].name, name) == 0)
            return 1; // True
    }
    return 0; // False
}

// Adiciona no array
void add_Contact(char name[], char phone[], Contato *c)
{
    strcpy(c[used].name, name);
    strcpy(c[used].phone, phone);

    used++;
    system(clear_Command);
    printf("|=======================================================|\n");
    printf(" '%s' ADICIONADO(A) À LISTA DE CONTATOS!             \n", name);
    printf("|=======================================================|\n\n");

    blink_loading();

    show_Contacts(c);
}

// Deleta no array e organiza
void delete_Contact(char name[], Contato *c)
{
    // Procura no array
    for (int i = 0; i < used; i++)
    {
        if (strcmp(c[i].name, name) == 0)
        {
            // Reorganizar array
            for (int j = i + 1; j < used; j++)
            {
                c[j - 1] = c[j];
            }

            used--;
            system(clear_Command);
            printf("|=======================================================|\n");
            printf("'%s' FOI EXCLUIDO(A) DA LISTA DE CONTATOS!           \n", name);
            printf("|=======================================================|\n\n");
            blink_loading();
            show_Contacts(c);
        }
    }
}

void find_contact_by_name(char name[], Contato *c)
{
    for (int i = 0; i < used; i++)
    {

        if (strcmp(c[i].name, name) == 0)
        {
            system(clear_Command);
            printf("|=======================================================|\n");
            printf("|                      CONTATO %i                        |\n", i + 1);
            printf("|=======================================================|\n");
            printf("| Nome: %-48s|\n", c[i].name);
            printf("| Telefone: %-44s|\n", c[i].phone);

            return;
        }

        else
        {
            system(clear_Command);
            printf("|=======================================================|\n");
            printf("|                 CONTATO NAO ENCONTRADO                |\n");
            printf("|=======================================================|\n\n");
        }
    }
}