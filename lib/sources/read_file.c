/*
** EPITECH PROJECT, 2021
** B-PSU-200-TLS-2-1-mysokoban-maceo.jalbert
** File description:
** read_file.c
*/

#include "lib.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static int open_file(const char *path)
{
    int fd = 0;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        my_puterror("my_sokoban: can't open the file.", 84);
    return fd;
}

static char *get_file_content(int fd, struct stat *info)
{
    char *buffer = NULL;
    unsigned int len = info->st_size / sizeof(char) + sizeof(char);

    buffer = malloc(len);
    if (buffer == NULL)
        return my_puterror_s("my_sokoban: can't alloc buffer");
    memset(buffer, '\0', len);
    if (read(fd, buffer, len) <= 0) {
        free(buffer);
        return my_puterror_s("my_sokoban: can't read the file");
    }
    return buffer;
}

char *read_file(const char *path)
{
    int fd = 0;
    struct stat *info = NULL;
    char *buffer = NULL;

    fd = open_file(path);
    if (fd < 0)
        return NULL;
    info = malloc(sizeof(struct stat));
    if (info == NULL) {
        close(fd);
        return NULL;
    }
    if (fstat(fd, info) < 0) {
        close(fd);
        return NULL;
    }
    buffer = get_file_content(fd, info);
    close(fd);
    free(info);
    return buffer;
}
