

NAME	:= Game
CFLAGS	:= -Wextra -Wall -Werror -Imlx

HEADERS	:= -I ./include -I ./gnl/get_next_line.h
SRCS	:= ./main.c ./parse.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
