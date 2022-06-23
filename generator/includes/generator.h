/*
** EPITECH PROJECT, 2021
** B-CPE-200-TLS-2-1-dante-christophe.chhor
** File description:
** generator.h
*/

#ifndef _GENERATOR_H_
    #define _GENERATOR_H_
    #define WALL 'X'
    #define FREE_SPACE '*'
    #define PATH 'P'
    #define TRUE 't'
    #define FALSE 'f'
    #include "lib.h"

// types
typedef struct {
    int x;
    int y;
}position_t;

typedef enum direction_e {
    UP = 0,
    DOWN,
    LEFT,
    RIGHT
}direction_t;

typedef struct {
    char **map;
    int x_len;
    int y_len;
}map_t;

// args_management.c
int check_usage(const int argc, const char **argv);
int check_args(const int argc, const char **argv);

// generator.c
int generate(const int argc, const char **argv);

// flood_fill.c
int flood_fill(map_t map);
int check_pos(position_t position, map_t map);
int find_map(position_t *curr_pos, map_t map, int *end_fix);
int is_pos_valid(position_t position, map_t map);
int move_dir(position_t *curr_pos, map_t map, direction_t direction);
int go_to_path(position_t *curr_pos, map_t map);

// position.c
int increment_pos(position_t pos, map_t map, int cmpt);
int check_pos(position_t position, map_t map);
int check_valid_pos(position_t *curr_pos, map_t map, char value, int plus);
int find_path(position_t *current_pos, map_t map, char axis, int plus);

// create_map.c
char **create_start_map(const unsigned int x, const unsigned int y);
int set_map_data(map_t *map);

// fix_end.c
int fix_end(position_t *pos, map_t map);
#endif
