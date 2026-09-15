NAME = gitplant.a
CC = gcc
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
ARGS = -Wall -Wextra -Werror

test : all
	./$(NAME)

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

.PHONY: all clean fclean re
