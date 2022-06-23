/*
** EPITECH PROJECT, 2022
** B-PSU-101-TLS-1-1-minishell1-christophe.chhor
** File description:
** count_idx_pos
*/

#include "lib.h"

int count_idx(char *str, char *separator, int idx, int tmp)
{
    for (; count_char_in_str(str[idx + tmp], separator) != 0; idx++)
        if (str[idx + tmp] == '\0')
            break;
    return idx;
}
