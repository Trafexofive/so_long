


#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
# include <stdbool.h>
#include "./libft/libft.h"


# define true 1
# define false 0
# define ERROR_1 "Invalid Map : .ber format required\n"
# define ERROR_2 "Failed to read map.\n"
# define ERROR_3 "Failed to provide map.\n"
# define ERROR_4 "Invalid map\n"
# define ERROR_5 "Invalid map : unable to find path to object\n"
# define ERROR_6 "\n"
# define ERROR_7 "\n"
# define ERROR_8 "\n"
# define ERROR_9 "\n"
# define ERROR_10 "\n"
# define ERROR_11 "\n"

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


char	*read_file(char *map_name, t_game_info *data);
void	ft_errors_exit(char *error_macro);
void	ft_errors(char *error_macro);
int	valid_walls(char *line);
bool allowed_elements(t_counter *elements);
bool	valid_element(char **map, int i , int j , t_counter *elements);



#endif
