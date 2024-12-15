##
## EPITECH PROJECT, 2023
## ftp_faut_git_clone
## File description:
## Makefile
##

SRC =	src/main.c					\
		src/create_socket.c			\
		src/error_handling.c		\
		src/init_fd.c				\
		src/array_with_code.c		\
		src/init_value.c			\
		src/my_str_to_word_array.c	\
		src/cwd.c					\
		src/cdup.c					\
		src/pass.c					\
		src/pwd.c					\
		src/user.c					\
		src/noop.c					\
		src/help.c					\
		src/quit.c					\
		src/list.c					\

CC = gcc

NAME =        myftp

CFLAGS =     -Wall -Wextra

CPPFLAGS	= -iquote include

OBJ    =    $(SRC:.c=.o)

all:    $(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

debug: CFLAGS += -g
debug: all

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJ)

re: fclean all clean debug
