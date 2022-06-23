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
    #define PATH 'o'
    #define SEEN 'S'
    #define TRUE 't'
    #define FALSE 'f'
    #include "lib.h"
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>

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

/* functions */
// move.c
bool go_forward(map_t map, position_t *pos);
int go_back(map_t map, position_t *pos);
// solver.c
int solve(map_t map);
#endif
