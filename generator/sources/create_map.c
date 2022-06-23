/*
** EPITECH PROJECT, 2021
** B-CPE-200-TLS-2-1-dante-christophe.chhor
** File description:
** create_map.c
*/

#include "generator.h"
#include "stdlib.h"
#include "lib.h"

static int set_lines(char **map, const unsigned int x, const unsigned int y)
{
    for (unsigned int l_index = 0; l_index < y; l_index++) {
        map[l_index] = malloc(sizeof(char) * (x + 1));
        if (map[l_index] == NULL)
            return my_puterror("set_lines: can't alloc line.\n", ERR);
        memset(map[l_index], 'X', x);
        map[l_index][x] = '\0';
    }
    map[y] = NULL;
    return STD;
}

char **create_start_map(const unsigned int x, const unsigned int y)
{
    char **map = NULL;

    if (x == 0 || y == 0)
        return (char **)my_puterror_s("./generator: x or y is equal to 0.\n");
    map = malloc(sizeof(char *) * (y + 1));
    if (map == NULL)
        return (char **)my_puterror_s("./generator: can't alloc map.\n");
    if (set_lines(map, x, y) == ERR) {
        free(map);
        return NULL;
    }
    return map;
}

int set_map_data(map_t *map)
{
    map->x_len = strlen(map->map[0]);
    for (map->y_len = 0; map->map[map->y_len] != NULL; map->y_len++);
    return STD;
}
