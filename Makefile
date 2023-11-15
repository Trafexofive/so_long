# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 07:37:31 by mlamkadm          #+#    #+#              #
#    Updated: 2023/11/15 07:38:31 by mlamkadm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

NAME	:= so_long

CFLAGS	:= -Wextra -Wall -Werror -Imlx

SRCS	:=  Mandatory/game/draw.c \
            Mandatory/game/hooks.c \
            Mandatory/parse/flood_field.c \
            Mandatory/parse/init_textures.c \
            Mandatory/parse/parse.c \
            Mandatory/parse/parse_map_utils.c \
            Mandatory/sl_utils.c \
            Mandatory/so_long.c

LIBFT_A := libft/libft.a

HEADERS := Mandatory/inc/so_long.h	Mandatory/inc/defines.h	  \

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
