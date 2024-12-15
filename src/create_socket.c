/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** server
*/

#include "my.h"

int create_s_socket(int port)
{
    struct sockaddr_in s_in = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY
    };
    int s_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (s_sock < 0)
        return 1;
    if (bind(s_sock, (const struct sockaddr *)&s_in, sizeof(s_in)))
        return 1;
    if (listen(s_sock, 1))
        return 1;
    return s_sock;
}

int create_c_socket(int s_sock)
{
    int c_sock = accept(s_sock, NULL, NULL);
    if (c_sock < 0)
        return 1;
    return c_sock;
}
