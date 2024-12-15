/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** pass
*/

#include "my.h"

void pass(var_t *var, int c_sock, int i, char *buffer)
{
    char **token = my_str_to_word_array(buffer, " \t\n");

    if (var->client[i].pass == true) {
        dprintf(c_sock, "230 Already logged in.\n");
        free_array(token);
        return;
    }
    if (var->client[i].pass == false) {
        if (strcasecmp(token[0], "PASS") == 0 &&
        var->client[i].connected == true) {
            dprintf(c_sock, "230 User logged in, proceed.\n");
            var->client[i].pass = true;
        }
    }
    if (strcasecmp(token[0], "PASS") == 0 &&
    var->client[i].connected == false) {
        dprintf(c_sock, "530 Not logged in\n");
    }
    free_array(token);
}
