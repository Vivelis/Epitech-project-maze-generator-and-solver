/*
** EPITECH PROJECT, 2021
** B-CPE-200-TLS-2-1-dante-christophe.chhor
** File description:
** args_management.c
*/

#include <stdio.h>
#include <string.h>
#include "lib.h"

static void print_usage(void)
{
    printf("USAGE\n\t./generator x y [perfect]\n");
    printf("INPUT\n\tx\t nbr of columns.\n");
    printf("\ty\t nbr of lines.\n");
    printf("\tperfect\t[optional] type of maze (default imperfect).\n");
}

int check_usage(const int argc, const char **argv)
{
    if (argc < 2)
        return my_puterror("./generator: missing args\n", ERR);
    if (strncmp(argv[1], "-h", 2) == 0) {
        print_usage();
        return STD;
    }
    if (strncmp(argv[1], "--help", 6) == 0) {
        print_usage();
        return STD;
    }
    return 1;
}

int check_args(const int argc, const char **argv)
{
    const int args_min = 3;
    const int args_max = 4;

    if (argc < args_min)
        return my_puterror("./generator: missing arguments.\n", ERR);
    if (argc > args_max)
        return my_puterror("./generator: too many arguments.\n", ERR);
    if (argc == args_max && strcmp(argv[3], "perfect") != 0)
        return my_puterror("./generator: bad third argument.\n", ERR);
    return STD;
}
