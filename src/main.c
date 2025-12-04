// PROJETO AGENDA EM C
// ESTUDANTES: HENRIQUE S., YAGO,YURI, GABRIEL FLÔR, EMANOEl.

// BIBLIOTECAS UTILIZADAS
#include <stdio.h>  //Lib Padrão
#include <stdlib.h> //Lib Padrão
#include <unistd.h> // #include <windows.h> //No windows
#include <string.h> //Biblioteca de string
#include "main.h"   //Incluo o struct Contato que criei em outro arquivo

#include <ctype.h>   // Necessário para isalpha() e isdigit()
#include <stdbool.h> //Permite tipos booleano

#define QTY 10 // Quantidade de contatos possíveis
int used = 1;  // Defino uma variavél global para saber a quantidade de posicoes do meu array Contatos

// Função que mostra o menu e retorna a opção escolhida pelo usuário
int show_Menu()
{
    char temp[10]; // Buffer de texto
    int opc;

    printf("=========================================\n");
    printf("         AGENDA  DE  CONTATO             \n");
    printf("=========================================\n");
    printf("   [1]  Listar contatos\n");
    printf("   [2]  Pesquisar contato\n");
    printf("   [3]  Adicionar contato\n");
    printf("   [4]  Excluir contato\n");
    printf("   [5]  Sair\n");
    printf("-----------------------------------------\n");
    printf("   Escolha uma opção: ");

    fgets(temp, 10, stdin);
    opc = atoi(temp);

    return opc;
}
// Mostrar lista de Contatos
void show_Contats(Contato *c)
{
    system("clear"); // cls para windows

    printf("----Lista de Contatos----\n\n");
    for (int i = 0; i < used; i++)
    {
        printf("---CONTATO %i---\n", i + 1);
        printf("Nome: %s\n", c[i].name);
        printf("Telefone: %s\n", c[i].phone);
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
    printf("Contato '%s' adicionado a lista de contatos!!\n", name);

    sleep(2); // No Linux é segundos, Windows: milisegundos

    show_Contats(c);
};
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
            system("clear"); // cls para windows
            printf("'%s' foi excluido(a) da sua lista de contatos!!\n", name);
            sleep(2); // No Linux é segundos, Windows: milisegundos
            show_Contats(c);
        }
    }
}
// Valida digitos do nome
int validate_Name(char *name)
{
    if (strlen(name) == 0 || strlen(name) >= 50)
        return 0;

    size_t len = strlen(name);

    for (size_t i = 0; i < len; i++)
    {
        if (!isalpha((unsigned char)name[i]) && name[i] != ' ')
            return 0;
    }
    return 1;
}
// Valida digitos do telefone
int validate_Phone(char *phone)
{
    if (strlen(phone) < 8 || strlen(phone) >= 15)
        return 0;

    size_t len = strlen(phone);

    for (size_t i = 0; i < len; i++)
    {
        if (!isdigit((unsigned char)phone[i]))
            return 0;
    }
    return 1;
}

// FUNÇÃO PRINCIPAL
int main(void)
{
    Contato c[QTY] = {{"Ana Clara", "47996235"}};
    char name[50];
    char phone[15];
    int opc = 0, exist;
    bool ok = false;

    // Looping principal
    while (opc != 5)
    {
        do
        {
            opc = show_Menu();

            if (opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5)
            {
                system("clear");
                printf("Opcao invalida!!\n");
            }

        } while (opc != 1 && opc != 2 && opc != 3 && opc != 4 && opc != 5);

        // Case para opções
        switch (opc)
        {
        case 1:
            // Printa os contatos
            show_Contats(c);
            break;
        case 2:
            break; // Adicionar funcionalidade de busca
        case 3:
            // Repete até o usuário digitar um contato que não existe
            do
            {
                do // Repete até ele digitar um nome válido
                {
                    printf("----Inclusão de contatos-----\n");
                    printf("Nome do novo contato: ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0'; // remove o \n

                    if (validate_Name(name))

                        ok = true;
                    else if (!validate_Name(name))
                    {
                        printf("Nome inválido!\n");
                        ok = false;
                    }

                } while (ok != true);

                // Quando valida nome reseta a varivel ok
                if (ok)
                    ok = false;

                exist = contact_Exists(name, c);
                if (exist)
                {
                    printf("Erro: Contato ja existe!!\n");
                    // system("clear"); // cls para windows
                }

            } while (exist != 0); // Enquanto oque ele digitar ja estiver no array

            while (ok != true) // Repete até ele digitar um numero válido
            {
                printf("Digite o Telefone: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = '\0'; // remove o \n

                if (validate_Phone(phone))
                    ok = true;
                else if (!validate_Phone(phone))
                {
                    system("clear"); // cls no windows
                    printf("Número de telefone inválido!!\n");
                    printf("Número tem que ter mais de 8 digitos!!\n");
                    ok = false;
                }
            }

            // Adiciona no array
            add_Contact(name, phone, c);
            break;
        case 4:
            // Deletar
            do
            {
                printf("----Exclusão de contatos-----\n");
                printf("Nome do contato: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove o \n

                exist = contact_Exists(name, c);

                if (!exist)
                {
                    printf("Erro: Contato não existe!!\n");
                    // system("clear"); // cls para windows
                }

            } while (exist == 0);

            // Deleta no array
            delete_Contact(name, c);
            break;
        default:
            break;
        }

        if (opc == 5)
        {
            system("clear");
            return printf("Até logo!\n");
        }
    }

    return 0;
}
