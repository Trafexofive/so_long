


#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <mlx.h>

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
	int	player;
	int	exit;
	int collectibles;
	int wall;
	int floor;
}t_map_count;
