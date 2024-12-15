/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** cdup
*/

#include <stdio.h>
#include "my.h"

void quit(var_t *var, int c_sock, int i, char *buffer)
{
    (void) buffer;
    (void) c_sock;
    FD_CLR(c_sock, &var->rfds);
    close(c_sock);
    var->client[i].c_sock = -1;
    return;
}
