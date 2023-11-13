

NAME	:= so_long 

CFLAGS	:= -Wextra -Wall  -Imlx
#-Werror
SRCS	:= main.c parse.c 

LIBFT_A := libft/libft.a

HEADERS := so_long.h libft/libft.h libft/gnl/get_next_line.h

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)
	 ./so_long
lib :
	make -C ./libft

$(NAME): $(OBJS) 
	$(CC) $(OBJS) $(LIBFT_A) -o $(NAME)

%.o: %.c $(HEADERS) | lib 
	$(CC) $(CFLAGS) -c $< -o $@ 


clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean lib all

.PHONY: all, lib, clean, fclean, re
