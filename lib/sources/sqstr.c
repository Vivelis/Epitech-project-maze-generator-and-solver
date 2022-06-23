/*
** EPITECH PROJECT, 2021
** B-CPE-200-TLS-2-1-dante-christophe.chhor
** File description:
** sqstr.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include "lib.h"

/* 
    Print an str array
    Don't forget to set the last index to NULL
    In case of error, return ERR. Else return STD.
*/
int sqstr_print(char **sq_str)
{
    if (sq_str == NULL)
        return my_puterror("print_sqstr: sq_str is NULL.\n", ERR);
    for (unsigned int index = 0; sq_str[index] != NULL; index++) {
        write(1, sq_str[index], strlen(sq_str[index]));
        if (sq_str[index + 1] == NULL) {
            break;
        } else {
            write(1, "\n", 1);
        }
    }
    return STD;
}

int sqstr_free(char **sq_str)
{
    if (sq_str == NULL)
        return 0;
    for (unsigned int index = 0; sq_str[index] != NULL; index++)
        free(sq_str[index]);
    free(sq_str);
    return 0;
}
