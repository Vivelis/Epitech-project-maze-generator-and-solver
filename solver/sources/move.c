/*
** EPITECH PROJECT, 2021
** B-CPE-200-TLS-2-1-dante-christophe.chhor
** File description:
** move.c
*/

#include "solver.h"

static bool is_pos_valid(int x, int y, map_t map)
{
    if (x < 0 || x >= map.x_len)
        return false;
    if (y < 0 || y >= map.y_len)
        return false;
    return true;
}

static bool check_pos_i(int x, int y, map_t map, char character)
{
    if (is_pos_valid(x, y, map) == false)
        return false;
    if (map.map[y][x] == character)
        return true;
    return false;
}

bool go_forward(map_t map, position_t *pos)
{
    if (check_pos_i(pos->x + 1, pos->y, map, FREE_SPACE) == true) {
        pos->x += 1;
        return true;
    }
    if (check_pos_i(pos->x, pos->y + 1, map, FREE_SPACE) == true) {
        pos->y += 1;
        return true;
    }
    if (check_pos_i(pos->x - 1, pos->y, map, FREE_SPACE) == true) {
        pos->x -= 1;
        return true;
    }
    if (check_pos_i(pos->x, pos->y - 1, map, FREE_SPACE) == true) {
        pos->y -= 1;
        return true;
    }
    return false;
}

int go_back(map_t map, position_t *pos)
{
    if (check_pos_i(pos->x - 1, pos->y, map, PATH) == true) {
        pos->x -= 1;
        return true;
    }
    if (check_pos_i(pos->x, pos->y - 1, map, PATH) == true) {
        pos->y -= 1;
        return true;
    }
    if (check_pos_i(pos->x + 1, pos->y, map, PATH) == true) {
        pos->x += 1;
        return true;
    }
    if (check_pos_i(pos->x, pos->y + 1, map, PATH) == true) {
        pos->y += 1;
        return true;
    }
    return false;
}
