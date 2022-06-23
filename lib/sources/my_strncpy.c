/*
** EPITECH PROJECT, 2022
** dante
** File description:
** my_strncpy
*/

#include <stdlib.h>
#include <string.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len_src = strlen(src);

    dest = malloc(sizeof(char) * (n + 2));
    for (; i < n && len_src > i; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
