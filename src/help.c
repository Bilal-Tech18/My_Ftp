/*
** EPITECH PROJECT, 2023
** my_ftp
** File description:
** help
*/

#include "my.h"

void help(var_t *var, int c_sock, int i, char *buffer)
{
    (void) buffer;
    (void) i;
    (void) var;
    if (var->client[i].pass == true) {
        dprintf(c_sock, "214-The following commands are recognized. ABOR");
        dprintf(c_sock, " ACCT ALLO APPE CDUP CWD  DELE EPRT EPSV FEAT ");
        dprintf(c_sock, "HELP LIST MDTM MKD MODE NLST NOOP OPTS PASS PASV ");
        dprintf(c_sock, "PORT PWD  QUIT REIN REST RETR RMD  RNFR RNTO SITE ");
        dprintf(c_sock, "SIZE SMNT STAT STOR STOU STRU SYST TYPE USER XCUP ");
        dprintf(c_sock, "XCWD XMKD XPWD XRMD\n");
        dprintf(c_sock, "214 Help OK.\n");
    } else
        dprintf(c_sock, "530 Please login with USER and PASS.\n");
    return;
}
