/*
** EPITECH PROJECT, 2022
** dante
** File description:
** position
*/

#include "generator.h"

int check_pos(position_t position, map_t map)
{
    if (position.x < 0 || position.x >= map.x_len)
        return FALSE;
    if (position.y < 0 || position.y >= map.y_len)
        return FALSE;
    return TRUE;
}

int increment_pos(position_t pos, map_t map, int cmpt)
{
    if (check_pos(pos, map) == TRUE && (map.map[pos.y][pos.x] == PATH ||
    map.map[pos.y][pos.x] == FREE_SPACE)) {
        cmpt++;
    }
    return cmpt;
}

int find_path(position_t *current_pos, map_t map, char axis, int plus)
{
    position_t pos;

    pos = (position_t) {current_pos->x, current_pos->y};
    if (axis == 'x') {
        pos.x += plus;
    }
    if (axis == 'y') {
        pos.y += plus;
    }
    if (check_pos(pos, map) == TRUE &&
    map.map[pos.y][pos.x] == PATH) {
        current_pos->x = pos.x;
        current_pos->y = pos.y;
        return STD;
    }
    return 1;
}

int is_pos_valid(position_t pos, map_t map)
{
    position_t start_pos = pos;
    unsigned int cmpt = 0;

    if (check_pos(pos, map) == FALSE || map.map[pos.y][pos.x] == PATH ||
    map.map[pos.y][pos.x] == FREE_SPACE)
        return FALSE;
    pos.y = start_pos.y + 1;
    cmpt = increment_pos(pos, map, cmpt);
    pos.y = start_pos.y - 1;
    cmpt = increment_pos(pos, map, cmpt);
    pos = start_pos;
    pos.x = start_pos.x + 1;
    cmpt = increment_pos(pos, map, cmpt);
    pos.x = start_pos.x - 1;
    cmpt = increment_pos(pos, map, cmpt);
    if (cmpt > 1)
        return FALSE;
    return TRUE;
}

int check_valid_pos(position_t *curr_pos, map_t map, char value, int plus)
{
    position_t pos = {curr_pos->x, curr_pos->y};

    if (value == 'y') {
        pos.y += plus;
    }
    if (value == 'x') {
        pos.x += plus;
    }
    if (is_pos_valid(pos, map) == FALSE) {
        return FALSE;
    }
    curr_pos->x = pos.x;
    curr_pos->y = pos.y;
    return TRUE;
}
