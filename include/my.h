/*
** EPITECH PROJECT, 2023
** ftp_faut_git_clone
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <sys/select.h>
    #include <sys/param.h>
    #include <string.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <ctype.h>

typedef struct client_s {
    char *buffer;
    int c_sock;
    char *pwd;
    bool connected;
    bool pass;
    int tick;
} client_t;

typedef struct var_s {
    int error;
    int s_sock;
    int max_fd;
    int nb_clients;
    fd_set rfds;
    int len_home;
    char home_path[PATH_MAX];
    client_t client[FD_SETSIZE];
} var_t;

void init_all_value(var_t *var);
int error_input(int ac, char **av);
int create_s_socket(int port);
int create_c_socket(int s_sock);
int error_handling(var_t *var);
void init_fd(var_t *var);
void max_fd_in_clients(var_t *var);
void fd_set_all(var_t *var);
void parce_fd(var_t *var);
void free_array(char **array);

void reply_to_clients(var_t *var, int c_sock, char *buffer, int i);
char **my_str_to_word_array(char *str, char *delim);
void user(var_t *var, int c_sock, int i, char *buffer);
void pass(var_t *var, int c_sock, int i, char *buffer);
void pwd(var_t *var, int c_sock, int i, char *buffer);
void noop(var_t *var, int c_sock, int i, char *buffer);
void cwd(var_t *var, int c_sock, int i, char *buffer);
void cdup(var_t *var, int c_sock, int i, char *buffer);
void help(var_t *var, int c_sock, int i, char *buffer);
void quit(var_t *var, int c_sock, int i, char *buffer);
void list(var_t *var, int c_sock, int i, char *buffer);

static const struct {
    char *cmd;
    void (*func) (var_t *var, int c_sock, int i, char *buffer);
} CMDS_FUNCTIONS[] = {
    {"PASS", &pass},
    {"USER", &user},
    {"PWD", &pwd},
    {"CWD", &cwd},
    {"CDUP", &cdup},
    {"HELP", &help},
    {"QUIT", &quit},
    {"LIST", &list},
    {"NOOP", &noop}
};

    #define NB_COMMANDS sizeof(CMDS_FUNCTIONS) / sizeof(CMDS_FUNCTIONS[0])

#endif /* !MY_H_ */
