/*
** EPITECH PROJECT, 2021
** B-CPE-200-TLS-2-1-dante-christophe.chhor
** File description:
** unit_tests.c
*/

#include "lib.h"
#include <criterion/criterion.h>

Test(my_str_to_array, one_line)
{
    char **result = NULL;
    char *str = "str";

    result = my_str_to_array(str, "\n");
    cr_assert_eq(result[1], NULL);
    for (int index = 0; result[index] != NULL; index++) {
        cr_assert_str_eq(result[index], str);
    }
}

Test(my_str_to_array, tree_line)
{
    char **result = NULL;
    char *str = "line\nline\nline";

    result = my_str_to_array(str, "\n");
    cr_assert_eq(result[3], NULL);
    for (int index = 0; result[index] != NULL; index++) {
        cr_assert_str_eq(result[index], "line");
    }
}
