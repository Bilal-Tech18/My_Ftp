/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** array_with_code
*/

#include "my.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
}

void reply_to_clients(var_t *var, int c_sock, char *buffer, int x)
{
    int len = strlen(buffer);
    int tick = 0;
    buffer[len - 1] = '\0';
    char **token = my_str_to_word_array(buffer, " \r\n");
    for (size_t i = 0; i < NB_COMMANDS; i++) {
        if (token[0] != NULL && strcasecmp(CMDS_FUNCTIONS[i].cmd,
        token[0]) == 0) {
            CMDS_FUNCTIONS[i].func(var, c_sock, x, buffer);
            tick = 1;
        }
    }
    if (tick == 0)
        dprintf(c_sock, "500 Unknown command.\n");
    free_array(token);
}
