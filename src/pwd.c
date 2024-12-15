/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** pwd
*/

#include "my.h"

void pwd(var_t *var, int c_sock, int i, char *buffer)
{
    (void) buffer;
    (void) i;
    if (var->client[i].pass == false) {
        dprintf(c_sock, "530 Please login with USER and PASS.\n");
        return;
    }
    if (var->client[i].pass == true && strlen(var->client[i].pwd) == 0) {
        getcwd(var->client[i].pwd, FD_SETSIZE);
        dprintf(c_sock, "257 '%s' is the current directory\n",
        var->client[i].pwd);
    } else
        dprintf(c_sock, "257 '%s' is the current directory\n",
        var->client[i].pwd);
}
