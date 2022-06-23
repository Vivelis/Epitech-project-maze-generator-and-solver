/*
** EPITECH PROJECT, 2022
** dante_star
** File description:
** lib
*/

#ifndef LIB_H_
    #define LIB_H_
    #include <stddef.h>
    #include <string.h>
    #include <stdlib.h>
    #define ERR 84
    #define STD 0

// print_map.c
void print_map(char **);

// get_str_info.c
int get_line_len(const char *str, unsigned int *index);
char is_char_in_str(const char character, const char *str);
unsigned int get_char_amount(const char character, const char *str);

// my_puterror.c
int my_puterror(char *str, int error_num);
char *my_puterror_s(char *str);

// sqstr.c
int sqstr_print(char **sq_str);
int sqstr_free(char **sq_str);

// read_file.c
char *read_file(const char *path);

// my_strncpy.c
char *my_strncpy(char *dest, char const *src, int n);

// count_idx.c
int count_idx(char *str, char *separator, int idx, int tmp);

// count_char_in_str.c
int count_char_in_str(char c, char *str);

// my_str_to_array.c
char **my_str_to_array(char *str, char *separator);
#endif/* !LIB_H_ */
