/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** noop
*/

#include "my.h"

void noop(var_t *var, int c_sock, int i, char *buffer)
{
    char **token = my_str_to_word_array(buffer, " \t\n");
    (void) buffer;
    (void) i;
    (void) var;

    if (token[1] != NULL) {
        dprintf(c_sock, "501 Syntax error in parameters or arguments.\n");
        free_array(token);
        return;
    }
    if (var->client[i].pass == true)
        dprintf(c_sock, "200 Command okay.\n");
    else
        dprintf(c_sock, "530 Please login with USER and PASS.\n");
    free_array(token);
}
