/*
** EPITECH PROJECT, 2023
** ftp_faut_git_clone
** File description:
** error_handling
*/

#include "my.h"

int error_input(int ac, char **av)
{
    if (ac <= 2 || atoi(av[1]) == 0) {
        printf("Invalid argument try ./myftp -h\n");
        return 84;
    }
    if (chdir(av[2]) == -1)
        return 84;
    return 0;
}

int error_handling(var_t *var)
{
    if (var->s_sock == 1)
        return 84;
    getcwd(var->home_path, PATH_MAX);
    return 0;
}
