


#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
# include <stdbool.h>
#include "./libft/libft.h"


# define true 1
# define false 0
# define ERROR_1 "Map must be in .ber format.\n"
# define ERROR_2 "Failed to load map.\n"
# define ERROR_3 "Failed to provide map.\n"
# define ERROR_4 "\n"

typedef struct point
{
	int x;
	int y;
}t_point;

typedef struct s_counter
{
	unsigned int	player;
	t_point			p_pos;
	unsigned int	exit;
	unsigned int 	collectibles; // to keep
}t_counter;

// typedef struct elements 
// {
// 	int	player;
// 	int	exit;
// 	int collectibles;
// 	int wall;
// 	int floor;
// }t_map_elements;

typedef struct game_info
{
	char			**map;
	t_point			p_pos;
	unsigned int 	c_count;
	int 	width;
	int 	length;

}		t_game_info;

#endif
