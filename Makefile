NAME = gitplant.a
CC = gcc
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
ARGS = -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(ARGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(ARGS) -c $< -o $@

fclean : clean
	rm -f $(NAME)


clean :
	rm -f $(OBJS)

re : fclean all

test : all clean
	$(CC) $(ARGS) test.c $(NAME)

.PHONY: all clean fclean re
