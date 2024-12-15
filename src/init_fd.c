/*
** EPITECH PROJECT, 2023
** ftp_faut_git_clone
** File description:
** init_fd
*/

#include "my.h"

void init_fd(var_t *var)
{
    FD_ZERO(&var->rfds);
    FD_SET(var->s_sock, &var->rfds);
}

void max_fd_in_clients(var_t *var)
{
    for (int i = 0; i < var->nb_clients; i++) {
        if (var->max_fd < var->client[i].c_sock)
            var->max_fd = var->client[i].c_sock;
    }
}

void fd_set_all(var_t *var)
{
    for (int i = 0; i < var->nb_clients; i++) {
        FD_SET(var->client[i].c_sock, &var->rfds);
    }
}

static void parce_fd_in_loop(var_t *var, int i)
{
    char buffer[1024] = {0};

    if (var->client[i].tick == 0) {
        dprintf(var->client[i].c_sock, "220 Connection Establishment.\n");
        var->client[i].tick = 1;
    }
    if (FD_ISSET(var->client[i].c_sock, &var->rfds)) {
        int size = read(var->client[i].c_sock, buffer, 1024);
        if (size <= 0)
            return;
        buffer[size - 1] = '\0';
        reply_to_clients(var, var->client[i].c_sock, buffer, i);
    }
}

void parce_fd(var_t *var)
{
    for (int i = 0; i < var->nb_clients; i++) {
        parce_fd_in_loop(var, i);
    }
}
