CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = src/main.c src/finder.c src/helper.c src/reverse.c src/sort.c src/stack.c src/swap_push.c src/utils.c src/rotate.c src/parsing.c src/parsing_utils.c
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = include/include.h
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: all clean fclean re

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all