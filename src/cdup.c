/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** cdup
*/

#include "my.h"

void cdup(var_t *var, int c_sock, int i, char *buffer)
{
    char **token = my_str_to_word_array(buffer, " \t\n");
    char real_path[PATH_MAX];
    char fpath[PATH_MAX];
    int tick = 0;
    strcpy(fpath, var->client[i].pwd);
    strcat(fpath, "/");
    if (var->client[i].pass == true && token[1] == NULL) {
        strcat(fpath, "..");
        realpath(fpath, real_path);
        tick = 1;
    }
    if (tick == 1 && strncmp(var->home_path, real_path, var->len_home) == 0) {
        strcpy(var->client[i].pwd, real_path);
        dprintf(c_sock, "250 Requested file action okay, completed.\n");
        free_array(token);
        return;
    }
    dprintf(c_sock, "550 Failed to change directory.\n");
    free_array(token);
    return;
}
