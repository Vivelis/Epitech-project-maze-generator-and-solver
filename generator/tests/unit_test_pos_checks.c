/*
** EPITECH PROJECT, 2021
** B-CPE-200-TLS-2-1-dante-christophe.chhor
** File description:
** unit_test_pos_checks.c
*/

#include "generator.h"
#include <criterion/criterion.h>

Test(move_dir, centered_pos_down)
{
    position_t pos = {2, 2};
    int result = 0;
    map_t map;

    map.map = create_start_map(5, 5);
    set_map_data(&map);
    result = move_dir(&pos, map, DOWN);
    cr_assert_eq(result, TRUE, "expect : \'t\' but got : \'%c\'", result);
    cr_assert_eq(pos.x, 2);
    cr_assert_eq(pos.y, 3);
}

Test(move_dir, centered_pos_up)
{
    position_t pos = {2, 2};
    int result = 0;
    map_t map;

    map.map = create_start_map(5, 5);
    set_map_data(&map);
    result = move_dir(&pos, map, UP);
    cr_assert_eq(result, TRUE);
    cr_assert_eq(pos.x, 2);
    cr_assert_eq(pos.y, 1);
}

Test(move_dir, centered_pos_right)
{
    position_t pos = {2, 2};
    int result = 0;
    map_t map;

    map.map = create_start_map(5, 5);
    set_map_data(&map);
    result = move_dir(&pos, map, RIGHT);
    cr_assert_eq(result, TRUE);
    cr_assert_eq(pos.x, 3);
    cr_assert_eq(pos.y, 2);
    sqstr_free(map.map);
}

Test(move_dir, centered_pos_left)
{
    position_t pos = {2, 2};
    int result = 0;
    map_t map;

    map.map = create_start_map(5, 5);
    set_map_data(&map);
    result = move_dir(&pos, map, LEFT);
    cr_assert_eq(result, TRUE);
    cr_assert_eq(pos.x, 1);
    cr_assert_eq(pos.y, 2);
    sqstr_free(map.map);
}

Test(move_dir, errorh_down)
{
    position_t pos = {4, 5};
    int result = 0;
    map_t map;

    map.map = create_start_map(5, 5);
    set_map_data(&map);
    result = move_dir(&pos, map, DOWN);
    cr_assert_eq(result, FALSE);
    cr_assert_eq(pos.x, 4);
    cr_assert_eq(pos.y, 5);
    sqstr_free(map.map);
}

Test(move_dir, errorh_up)
{
    position_t pos = {3, 0};
    int result = 0;
    map_t map;

    map.map = create_start_map(5, 5);
    set_map_data(&map);
    result = move_dir(&pos, map, UP);
    cr_assert_eq(result, FALSE);
    cr_assert_eq(pos.x, 3);
    cr_assert_eq(pos.y, 0);
    sqstr_free(map.map);
}

Test(move_dir, errorh_right)
{
    position_t pos = {5, 2};
    int result = 0;
    map_t map;

    map.map = create_start_map(5, 5);
    set_map_data(&map);
    result = move_dir(&pos, map, RIGHT);
    cr_assert_eq(result, FALSE);
    cr_assert_eq(pos.x, 5);
    cr_assert_eq(pos.y, 2);
    sqstr_free(map.map);
}

Test(move_dir, errorh_left)
{
    position_t pos = {0, 3};
    int result = 0;
    map_t map;

    map.map = create_start_map(5, 5);
    set_map_data(&map);
    result = move_dir(&pos, map, LEFT);
    cr_assert_eq(result, FALSE);
    cr_assert_eq(pos.x, 0);
    cr_assert_eq(pos.y, 3);
    sqstr_free(map.map);
}
