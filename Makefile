CC := cc

NAME	:= so_long

CFLAGS	:= -Wextra -Wall -Imlx
#-Werror
SRCS	:=  so_long.c parse.c	parse_map_utils.c error_utils.c 

LIBFT_A := libft/libft.a

HEADERS := so_long.h libft/libft.h

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT_A) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

lib : 
	make -C ./libft

%.o: %.c $(HEADERS) | lib
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all, lib, clean, fclean, re
