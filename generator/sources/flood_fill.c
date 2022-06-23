/*
** EPITECH PROJECT, 2021
** B-CPE-200-TLS-2-1-dante-christophe.chhor
** File description:
** flood_fill.c
*/

#include "generator.h"
#include <stdlib.h>
#include <time.h>

int go_to_path(position_t *curr_pos, map_t map)
{
    if (find_path(curr_pos, map, 'y', -1) == STD)
        return STD;
    if (find_path(curr_pos, map, 'y', 1) == STD)
        return STD;
    if (find_path(curr_pos, map, 'x', -1) == STD)
        return STD;
    if (find_path(curr_pos, map, 'x', 1) == STD)
        return STD;
    return ERR;
}

int move_dir(position_t *curr_pos, map_t map, direction_t direction)
{
    switch (direction) {
        case UP:
            return check_valid_pos(curr_pos, map, 'y', -1);
        case DOWN:
            return check_valid_pos(curr_pos, map, 'y', 1);
        case RIGHT:
            return check_valid_pos(curr_pos, map, 'x', 1);
        case LEFT:
            return check_valid_pos(curr_pos, map, 'x', -1);
    }
    return ERR;
}

int move(position_t *curr_pos, map_t map)
{
    direction_t direction = UP;
    unsigned int cmpt = 0;

    direction = rand() % 4;
    while (cmpt < 4) {
        if (move_dir(curr_pos, map, (direction + cmpt) % 4) == TRUE)
            return TRUE;
        cmpt++;
    }
    return FALSE;
}

int find_map(position_t *curr_pos, map_t map, int *end_fix)
{
    if (*end_fix == TRUE)
        fix_end(curr_pos, map);
    if (move(curr_pos, map) == TRUE) {
        map.map[curr_pos->y][curr_pos->x] = PATH;
    } else {
        map.map[curr_pos->y][curr_pos->x] = FREE_SPACE;
        if (go_to_path(curr_pos, map) == ERR)
            return ERR;
    }
    return STD;
}

int flood_fill(map_t map)
{
    time_t curr_time;
    int end_fix = FALSE;
    position_t curr_pos = {0, 0};

    srand((unsigned int)time(&curr_time));
    map.map[0][0] = PATH;
    do {
        if (find_map(&curr_pos, map, &end_fix) == ERR) {
            return ERR;
        }
    } while (!(curr_pos.x == 0 && curr_pos.y == 0));
    map.map[curr_pos.y][curr_pos.x] = FREE_SPACE;
    map.map[map.y_len - 1][map.x_len - 1] = FREE_SPACE;
    return 0;
}
