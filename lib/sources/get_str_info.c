/*
** EPITECH PROJECT, 2021
** B-PSU-200-TLS-2-1-mysokoban-maceo.jalbert
** File description:
** get_str_info.c
*/

#include "lib.h"

int get_line_len(const char *str, unsigned int *index)
{
    int line_len = 0;

    if (str == NULL || index == NULL)
        return my_puterror("get_line_len: str or index is NULL.\n", -1);
    for (; str[*index] != '\n' && str[*index] != '\0'; *index += 1) {
        line_len++;
    }
    return line_len;
}

char is_char_in_str(const char character, const char *str)
{
    if (str == NULL)
        return 'e';
    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] == character)
            return 'y';
    }
    return 'n';
}

unsigned int get_char_amount(const char character, const char *str)
{
    unsigned int amount = 0;

    if (str == NULL)
        return 0;
    for (unsigned int index = 0; str[index] != '\0'; index++) {
        if (str[index] == character)
            amount++;
    }
    return amount;
}
