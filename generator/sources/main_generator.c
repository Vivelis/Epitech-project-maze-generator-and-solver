/*
** EPITECH PROJECT, 2021
** B-CPE-200-TLS-2-1-dante-christophe.chhor
** File description:
** main_generator.c
*/

#include "generator.h"
#include <stdio.h>

int main(int argc, const char **argv)
{
    int errorh = 1;

    errorh = check_usage(argc, argv);
    if (errorh != 1)
        return errorh;
    errorh = check_args(argc, argv);
    if (errorh != STD)
        return errorh;
    errorh = generate(argc, argv);
    return errorh;
}
