/*
** EPITECH PROJECT, 2023
** en_cours
** File description:
** list
*/

#include "my.h"
#include <dirent.h>

void simple_ls(char *path, int c_sock)
{
    DIR *dir = opendir(path);
    struct dirent *file;

    for (; (file = readdir(dir)) != 0;) {
        if (file->d_name[0] != '.') {
            dprintf(c_sock, "%s", file->d_name);
            dprintf(c_sock, " ");
        }
    }
    dprintf(c_sock, "\n");
    closedir(dir);
}

void list(var_t *var, int c_sock, int i, char *buffer)
{
    (void) buffer;
    if (var->client[i].pass == true)
        simple_ls(var->client[i].pwd, c_sock);
}
