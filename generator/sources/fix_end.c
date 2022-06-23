/*
** EPITECH PROJECT, 2021
** B-CPE-200-TLS-2-1-dante-christophe.chhor
** File description:
** fix_end.c
*/

#include "generator.h"

// static int check_pos_i(int x, int y, map_t map)
// {
//     if (x < 0 || x >= map.x_len)
//         return FALSE;
//     if (y < 0 || y >= map.y_len)
//         return FALSE;
//     return TRUE;
// }

// void fix_end(map_t map)
// {
//     int x = map.x_len - 1;
//     int y = map.y_len - 1;

//     map.map[y][x] = FREE_SPACE;
//     if ((check_pos_i(x, y - 1, map) == TRUE && map.map[y - 1][x] == WALL) &&
//      (check_pos_i(x - 1, y, map) == TRUE && map.map[y][x - 1] == WALL)) {
//         map.map[y][x - 1] = FREE_SPACE;
//     }
// }

static void set_path(map_t map)
{
    if (map.x_len >= 3 && map.map[map.y_len - 1][map.x_len - 3] != PATH) {
        map.map[map.y_len - 1][map.x_len - 2] = PATH;
    }
    if (map.y_len >= 3 && map.map[map.y_len - 3][map.x_len - 1] != PATH) {
        map.map[map.y_len - 1][map.x_len - 2] = PATH;
    }
}

int fix_end(position_t *pos, map_t map)
{
    if (pos->x < map.x_len - 2 && pos->y < map.y_len - 2) {
        return STD;
    }
    if (pos->x == map.x_len - 2 && pos->y == map.y_len - 2) {
        set_path(map);
    }
    pos->y = map.y_len - 1;
    pos->x = map.x_len - 1;
    map.map[pos->y][pos->x] = PATH;
    return STD;
}
