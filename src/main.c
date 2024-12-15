/*
** EPITECH PROJECT, 2023
** ftp_faut_git_clone
** File description:
** main
*/

#include "my.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void display_help(void)
{
    printf("USAGE: ./myftp port\n");
    printf("       port is the port number on which the server socket listens.\n");
}

int main(int ac, char **av)
{
    if (ac != 2) {
        fprintf(stderr, "Invalid argument. Try ./myftp -h\n");
        return 84;
    }
    if (strcmp(av[1], "-h") == 0) {
        display_help();
        return 0;
    }
    if (atoi(av[1]) <= 0) {
        fprintf(stderr, "Invalid port number. Try ./myftp -h\n");
        return 84;
    }

    var_t var;
    var.s_sock = create_s_socket(atoi(av[1]));
    if (error_handling(&var) == 84)
        return 84;

    init_all_value(&var);
    while (1) {
        init_fd(&var);
        var.max_fd = var.s_sock;
        max_fd_in_clients(&var);
        fd_set_all(&var);
        if (select(var.max_fd + 1, &var.rfds, NULL, NULL, NULL) < 0)
            return 1;
        if (FD_ISSET(var.s_sock, &var.rfds)) {
            var.client[var.nb_clients].c_sock = create_c_socket(var.s_sock);
            var.nb_clients += 1;
        }
        parce_fd(&var);
    }
}
