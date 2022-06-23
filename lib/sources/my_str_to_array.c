/*
** EPITECH PROJECT, 2021
** lib
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "lib.h"

static int handle_error(char *str, char *separator, int nb_separator)
{
    if (str == NULL)
        return 84;
    if (separator == NULL)
        return 84;
    if (nb_separator == 0)
        return 84;
    return 0;
}

static int count_separator(char *str, char *separator)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (count_char_in_str(str[i], separator) == 0)
            result++;
    }
    return result;
}

static char **malloc_result(char *str, int nb_separator)
{
    char **result = NULL;

    if (nb_separator == 0) {
        result = malloc(sizeof(char *) * 2);
        result[0] = str;
        result[1] = NULL;
    } else {
        result = malloc(sizeof(char *) * (nb_separator + 2));
    }
    return result;
}

char **my_str_to_array(char *str, char *separator)
{
    int nb_separator = count_separator(str, separator);
    char **result = NULL;
    int tmp = 0;

    result = malloc_result(str, nb_separator);
    if (nb_separator == 0)
        return result;
    if (handle_error(str, separator, nb_separator) == 84)
        return NULL;
    for (int i = 0, idx = 0; i <= nb_separator; i++) {
        idx = count_idx(str, separator, idx, tmp);
        result[i] = my_strncpy(result[i], str + tmp, idx);
        tmp += idx + 1;
        idx = 0;
    }
    result[nb_separator + 1] = NULL;
    return result;
}
