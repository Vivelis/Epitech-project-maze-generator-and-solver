/*
** EPITECH PROJECT, 2021
** B-CPE-200-TLS-2-1-dante-christophe.chhor
** File description:
** unit_test_1.c
*/

#include "generator.h"
#include <criterion/criterion.h>

Test(create_start_map, zero_zero_map)
{
    char **result = NULL;

    result = create_start_map(0, 0);
    cr_assert_eq(result, NULL);
}

Test(create_start_map, one_one_map)
{
    char **result = NULL;
    unsigned int x = 1;
    unsigned int y = 1;

    result = create_start_map(x, y);
    for (unsigned int index = 0; index < y; index++) {
        cr_assert_str_eq(result[index], "X",
        "expect : \"%s\" but got : \"%s\"", "X", result[index]);
    }
    sqstr_free(result);
}

Test(create_start_map, ten_ten_map)
{
    char **result = NULL;
    unsigned int x = 10;
    unsigned int y = 10;

    result = create_start_map(x, y);
    for (unsigned int index = 0; index < y; index++) {
        cr_assert_str_eq(result[index], "XXXXXXXXXX",
        "expect : \"%s\" but got : \"%s\"", "X", result[index]);
    }
    sqstr_free(result);
}

Test(create_start_map, asymetric_10_1_map)
{
    char **result = NULL;
    unsigned int x = 10;
    unsigned int y = 1;

    result = create_start_map(x, y);
    for (unsigned int index = 0; index < y; index++) {
        cr_assert_str_eq(result[index], "XXXXXXXXXX",
        "expect : \"%s\" but got : \"%s\"", "XXXXXXXXXX", result[index]);
    }
    sqstr_free(result);
}

Test(create_start_map, asymetric_1_10_map)
{
    char **result = NULL;
    unsigned int x = 1;
    unsigned int y = 10;

    result = create_start_map(x, y);
    for (unsigned int index = 0; index < y; index++) {
        cr_assert_str_eq(result[index], "X",
        "expect : \"%s\" but got : \"%s\"", "X", result[index]);
    }
    sqstr_free(result);
}

Test(create_start_map, asymetric_10_5_map)
{
    char **result = NULL;
    unsigned int x = 10;
    unsigned int y = 5;

    result = create_start_map(x, y);
    for (unsigned int index = 0; index < y; index++) {
        cr_assert_str_eq(result[index], "XXXXXXXXXX",
        "expect : \"%s\" but got : \"%s\"", "XXXXXXXXXX", result[index]);
    }
    sqstr_free(result);
}

Test(create_start_map, asymetric_5_10_map)
{
    char **result = NULL;
    unsigned int x = 5;
    unsigned int y = 10;

    result = create_start_map(x, y);
    for (unsigned int index = 0; index < y; index++) {
        cr_assert_str_eq(result[index], "XXXXX",
        "expect : \"%s\" but got : \"%s\"", "XXXXX", result[index]);
    }
    sqstr_free(result);
}

Test(set_map_data, five_by_five)
{
    map_t map;
    unsigned int x = 5;
    unsigned int y = 10;

    map.map = create_start_map(x, y);
    set_map_data(&map);
    cr_assert_eq(map.x_len, 5);
    cr_assert_eq(map.y_len, 10);
}

Test(set_map_data, one_by_one)
{
    map_t map;
    unsigned int x = 1;
    unsigned int y = 1;

    map.map = create_start_map(x, y);
    set_map_data(&map);
    cr_assert_eq(map.x_len, 1);
    cr_assert_eq(map.y_len, 1);
}
