/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** init_value
*/

#include "my.h"

void init_all_value(var_t *var)
{
    var->error = 0;
    var->max_fd = 0;
    var->max_fd = 0;
    var->nb_clients = 0;
    var->len_home = strlen(var->home_path);
    for (int i = 0; i < FD_SETSIZE; i++) {
        var->client[i].connected = false;
        var->client[i].pass = false;
        var->client[i].tick = 0;
        var->client[i].pwd = malloc((sizeof(char)) * (PATH_MAX + 1));
        strcpy(var->client[i].pwd, var->home_path);
    }
}
