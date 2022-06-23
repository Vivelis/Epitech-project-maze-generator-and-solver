/*
** EPITECH PROJECT, 2022
** generator.c
** File description:
** main of generator
*/

#include <stddef.h>
#include <time.h>
#include "generator.h"
#include "lib.h"

int set_square(char **map, int x, int y)
{
    int x_max = 2;
    int y_max = 2;

    for (int y_nbr = 0; y_nbr < y_max; y_nbr++) {
        for (int x_nbr = 0; x_nbr < x_max; x_nbr++) {
            map[y + y_nbr][x + x_nbr] = FREE_SPACE;
        }
    }
    return STD;
}

int random_set(map_t map)
{
    int x = 0;
    int y = 0;
    time_t curr_time;

    if (map.x_len <= 1 || map.y_len <= 1)
        return ERR;
    srand((unsigned int)time(&curr_time));
    for (int cmpt = 0; cmpt < (map.x_len + map.y_len) / 4; cmpt++) {
        if (map.x_len - 2 != 0 || map.y_len - 2 != 0) {
            x = rand() % (map.x_len - 2);
            y = rand() % (map.y_len - 2);
        }
        set_square(map.map, x, y);
    }
    return STD;
}

int generate(const int argc, const char **argv)
{
    int output = STD;
    map_t map;

    map.map = create_start_map(atoi(argv[1]), atoi(argv[2]));
    if (map.map == NULL)
        return ERR;
    set_map_data(&map);
    flood_fill(map);
    if (!(argc == 4 && strcmp(argv[3], "perfect") == 0)) {
        random_set(map);
    }
    sqstr_print(map.map);
    sqstr_free(map.map);
    return output;
}
