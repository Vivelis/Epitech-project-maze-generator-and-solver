/*
** EPITECH PROJECT, 2022
** solver.c
** File description:
** main of solver part
*/

#include "solver.h"

static int arg_err(void)
{
    write(2, "Wrong arguments given, expected 2 arguments\n", 44);
    write(2, "example : ./solver [map]\n", 25);
    return 84;
}

static int set_map_data(map_t *map)
{
    map->x_len = strlen(map->map[0]);
    for (map->y_len = 0; map->map[map->y_len] != NULL; map->y_len++);
    return STD;
}

static int solver(char **av)
{
    char *str = NULL;
    map_t map;

    str = read_file(av[1]);
    if (str == NULL)
        return 84;
    map.map = my_str_to_array(str, "\n");
    if (map.map == NULL)
        return 84;
    set_map_data(&map);
    solve(map);
    sqstr_print(map.map);
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        return arg_err();
    } else {
        return solver(av);
    }
}
