/*
** EPITECH PROJECT, 2022
** dante_star
** File description:
** print_map
*/

#include <stddef.h>
#include <unistd.h>
#include <string.h>

void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        write(1, map[i], strlen(map[i]));
    }
}
