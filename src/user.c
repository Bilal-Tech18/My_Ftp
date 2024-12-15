/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** user
*/

#include "my.h"

void user(var_t *var, int c_sock, int i, char *buffer)
{
    char **token = my_str_to_word_array(buffer, " \t\n");

    if (token[1] != NULL && var->client[i].connected == false) {
        if (strcasecmp(token[0], "USER") == 0 && strcasecmp(token[1],
        "anonymous") == 0) {
            dprintf(c_sock, "331 User name okay, need password.\n");
            var->client[i].connected = true;
        return;
        }
    }
    if (var->client[i].connected == false) {
        dprintf(c_sock, "331 User name okay, need password.\n");
    }
    free_array(token);
}
