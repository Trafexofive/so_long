
#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
# include <stdbool.h>
#include "./libft/libft.h"


typedef enum keys
{
	W_KEY = 0x0D,
	S_KEY = 0x01,
	A_KEY = 0x00,
	D_KEY = 0x02,
} keys;


# define true 1
# define false 0
# define TILE 64
# define PLAYER_PATH "./textures/player.xpm"
# define floor_path "./textures/floor.xpm"
# define wall_path "./textures/wall.xpm"
# define exit_path "./textures/exit.xpm"
# define coin_path "./textures/coin.xpm"
# define ERROR_1 "Invalid Map : .ber format required\n"
# define ERROR_2 "Failed to read map.\n"
# define ERROR_3 "Failed to provide map.\n"
# define ERROR_4 "Invalid Map : Map must be surronded by walls\n"
# define ERROR_5 "Invalid Map : unable to find path to object\n"
# define ERROR_6 "Invalid args : Too many arguments\n"
# define ERROR_7 "Invalid Map : Map missing exit\n"
# define ERROR_8 "Invalid Map : Map missing player\n"
# define ERROR_9 "Invalid Map : Map must have at least one collectible\n"
# define ERROR_10 "\n"
# define ERROR_11 "\n"

typedef struct point
{
	int x;
	int y;
}				t_point;

typedef struct s_counter
{
	unsigned int	player;
	t_point			p_pos;
	t_point			e_pos;
	unsigned int	exit;
	unsigned int 	collectibles;
	// to keep
}				t_counter;

typedef struct s_img_data
{
	int		img_width;
	int		img_height;

	void	*floor_img;
	void	*wall_img;
	void	*coin_img;
	void	*exit_img;
	void	*player_img;

	int		tile_width;
	int		tile_lenght;
	// t_point	m_pos;
}			t_img_data;

typedef struct game_info
{
	void				*mlx;
	void				*mlx_win;
	char				**map;
	int 				width;
	int 				length;
	t_point				p_pos;
	unsigned int 		c_count;
	bool				exit_allowed;
	t_point				e_pos;
	struct s_img_data	textures;
}			t_game_info;

char	*read_file(char *map_name, t_game_info *data);
void	ft_errors_exit(char *error_macro);
void	ft_errors(char *error_macro);
int	valid_walls(char *line);
bool allowed_elements(t_counter *elements);
bool	valid_element(char **map, int i , int j , t_counter *elements);
t_game_info		*so_long(char **s1);
void	flood_field(char **flooded_map, int x, int y);
bool	valid_flow(char **map);
bool	valid_map(char *buffered_map, t_game_info *game);

#endif
