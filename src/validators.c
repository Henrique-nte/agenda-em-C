#include "../include/validators.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h> // Para usar bool ao invés de int para retorno booleano

// Valida digitos do nome
// Retorna true (1) se válido, false (0) se inválido.
int validate_Name(char *name)
{
    // Verifica limites de comprimento: mínimo 1, máximo 49 (pois o array de 50 precisa de espaço para \0)
    if (strlen(name) == 0 || strlen(name) >= 50)
        return false;

    size_t len = strlen(name);

    for (size_t i = 0; i < len; i++)
    {
        // Garante que o caractere seja alfanumérico ou um espaço.
        // O cast (unsigned char) é uma boa prática para evitar problemas de locale/caracteres negativos.
        if (!isalpha((unsigned char)name[i]) && name[i] != ' ')
            return false;
    }
    return true;
}

// Valida digitos do telefone
// Retorna true (1) se válido, false (0) se inválido.
int validate_Phone(char *phone)
{
    // Define limites razoáveis para telefones (ex: 8 dígitos para fixo simples, até 14/15 com DDI e máscara)
    if (strlen(phone) < 8 || strlen(phone) >= 16)
        return false;

    size_t len = strlen(phone);

    for (size_t i = 0; i < len; i++)
    {
        // Garante que todos os caracteres sejam dígitos numéricos.
        if (!isdigit((unsigned char)phone[i]))
            return false;
    }
    return true;
}
