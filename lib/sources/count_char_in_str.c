/*
** EPITECH PROJECT, 2022
** dante_star
** File description:
** count_char_in_str
*/

int count_char_in_str(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return 0;
    return 1;
}
