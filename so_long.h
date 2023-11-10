


#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include "./gnl/get_next_line.h"

typedef struct point
{
	int x;
	int y;
}t_point;

typedef struct player
{
	t_point	p;
}t_player;

typedef struct map_count
{
	static int	player;
	static int	exit;
	static int collectibles;
	static int wall;
	static int floor;
}t_map_count;

#endif
