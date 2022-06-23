/*
** EPITECH PROJECT, 2021
** B-CPE-200-TLS-2-1-dante-christophe.chhor
** File description:
** solver.c
*/

#include "solver.h"

static void remove_line_path(char *line, int len)
{
    for (int x = 0; x < len; x++) {
        if (line[x] == SEEN)
            line[x] = FREE_SPACE;
    }
}

static void remove_path(map_t map)
{
    for (int y = 0; y < map.y_len; y++) {
        remove_line_path(map.map[y], map.x_len);
    }
}

static int resolve(map_t map, position_t *curr_pos)
{
    while (go_forward(map, curr_pos) == false) {
        map.map[curr_pos->y][curr_pos->x] = SEEN;
        go_back(map, curr_pos);
        if (curr_pos->x == 0 && curr_pos->y == 0)
            return my_puterror("solve: go back to start.\n", ERR);
    }
    map.map[curr_pos->y][curr_pos->x] = PATH;
    return STD;
}

int solve(map_t map)
{
    position_t curr_pos = {0, 0};

    map.map[curr_pos.y][curr_pos.x] = PATH;
    while (!(curr_pos.x == map.x_len - 1 && curr_pos.y == map.y_len - 1)) {
        if (resolve(map, &curr_pos) == ERR)
            return ERR;
    }
    remove_path(map);
    return STD;
}
