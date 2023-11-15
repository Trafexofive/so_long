# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 07:37:31 by mlamkadm          #+#    #+#              #
#    Updated: 2023/11/15 07:46:07 by mlamkadm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

NAME	:= so_long

CFLAGS	:= -Wextra -Wall -Werror -Imlx

SRCS	:=  key_hunter/game/draw.c \
            key_hunter/game/hooks.c \
            key_hunter/parse/flood_field.c \
            key_hunter/parse/init_textures.c \
            key_hunter/parse/parse.c \
            key_hunter/parse/parse_map_utils.c \
            key_hunter/sl_utils.c \
            key_hunter/so_long.c

LIBFT_A := libft/libft.a

HEADERS := key_hunter/inc/so_long.h	key_hunter/inc/defines.h	  \

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
