#make file - this is a comment section

CC=gcc
TARGET=my_mastermind
CFLAGS = -Wall -Wextra -Werror
NAME=my_mastermind.c
OBJ=my_mastermind.o

all:
		$(CC) $(NAME) -o $(TARGET) $(CFLAGS)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean