/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:55:21 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/11/15 05:06:18 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H


# define TRUE 1
# define FALSE 0

# define TILE 64

/* #################  Texture  ################# */

# define PLAYER_PATH "../../textures/player.xpm"
# define FLOOR_PATH "../../textures/floor.xpm"
# define WALL_PATH "../../textures/wall.xpm"
# define EXIT_PATH "../../textures/exit.xpm"
# define COIN_PATH "../../textures/coin.xpm"

/* #################  Error_Messages  ################# */


# define ERROR_1 "Invalid Map : .ber format required\n"
# define ERROR_2 "Failed to read map.\n"
# define ERROR_3 "Failed to provide map.\n"
# define ERROR_4 "Invalid Map : Map must be surronded by walls\n"
# define ERROR_5 "Invalid Map : unable to find path to object\n"
# define ERROR_6 "Invalid args : Too many arguments\n"
# define ERROR_7 "Invalid Map : Map missing object\n"
# define ERROR_8 "Invalid Map : Map has duplicated object\n"
# define ERROR_9 "Invalid Map : Map must have at least one collectible\n"
# define ERROR_10 "Memory Error : Memory Failed to allocate \n"
# define ERROR_11 "Error : Texture not found\n"

/* #################  Key Hooks  ################# */

typedef enum keys
{
	W_KEY = 0x0D,
	S_KEY = 0x01,
	A_KEY = 0x00,
	D_KEY = 0x02,
	ESC_KEY= 0x35,
} keys;


/* #################  Structs  ################# */

typedef struct point
{
	int x;
	int y;
}				t_point;

typedef struct s_counter
{
	unsigned int	player;
	unsigned int	exit;
	unsigned int 	collectibles;

	t_point			e_pos;
	t_point			p_pos;
}				t_counter;

typedef struct s_img_data
{
	void	*floor_img;
	void	*wall_img;
	void	*coin_img;
	void	*exit_img;
	void	*player_img;

	int		img_width;
	int		img_height;

	
}			t_img_data;

typedef struct game_info
{
	void				*mlx;
	void				*mlx_win;

	bool				exit_allowed;

	int 				width;
	int 				length;

	char				**map;

	unsigned int 		c_count;
	unsigned int		move_count;

	t_img_data			textures;

	t_point				e_pos;
	t_point				p_pos;
}						t_game_info;





#endif