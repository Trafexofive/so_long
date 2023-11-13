#include "so_long.h"

int	draw_map(t_game_info *game)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(game->mlx,game->mlx_win);
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures.wall_img, TILE * j , TILE * i);
			else if (game->map[i][j] == '0' || game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures.floor_img, TILE * j, TILE * i);
			else if (game->map[i][j] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures.floor_img, TILE * j, TILE * i);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures.coin_img, TILE * j, TILE * i);
			}
			else if (game->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures.floor_img, TILE * j, TILE * i);
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures.exit_img, TILE * j, TILE * i);
			}
			j++;
		}
		i++;
		j = 0;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures.player_img, TILE * game->p_pos.x, TILE * game->p_pos.y);
	return(0);
}

void	*jadarmi(void *mlx_ptr, char *filename, int *width, int *height)
{
	void *p;

	p = NULL;
	p = mlx_xpm_file_to_image(mlx_ptr, filename, width, height);
	if (!p)
		exit(0);
	return (p);
}


void	*load_textures(t_game_info *game) // bool 
{
	game->textures.player_img = jadarmi(game->mlx, PLAYER_PATH, &game->textures.img_width, &game->textures.img_height); // missing handle error
	game->textures.coin_img = jadarmi(game->mlx, coin_path, &game->textures.img_width, &game->textures.img_height);
	game->textures.exit_img = jadarmi(game->mlx, exit_path, &game->textures.img_width, &game->textures.img_height);
	game->textures.floor_img = jadarmi(game->mlx, floor_path, &game->textures.img_width, &game->textures.img_height); // prottect against  null
	game->textures.wall_img = jadarmi(game->mlx, wall_path, &game->textures.img_width, &game->textures.img_height);
	return (NULL);
}

int  colision(char c)
{
	if (c == '1' || c == 'E')
		return (1);
	else if (c == 'C')
		return (3);
	else
		return(0);
}

void events(t_game_info *game , int x, int y) 
{
	game->p_pos.x += x;
	game->p_pos.y += y;
	// if (game->map[game->p_pos.y][game->p_pos.x] == 'C')
	// {
	// 	game->map[game->p_pos.y][game->p_pos.x] = '0';
	// 	game->c_count--;
	// }
	// if (game->map[game->p_pos.y + y][game->p_pos.x + x] == 'E' && game->c_count == 0)
	// {
	// 	exit(0);
	// }
	fprintf(stderr,"coins left = %d  ",game->c_count);
	// else if (colision(game->map[game->p_pos.y - 1][game->p_pos.x]) == 3)
	// {
	// 	game->map[game->p_pos.y - 1][game->p_pos.x] = '0';
	// 	game->c_count--;
	// }
	// if (colision(game->map[game->p_pos.y - 1][game->p_pos.x]) == 3)
	// {
	// 	game->map[game->p_pos.y - 1][game->p_pos.x] = '0';
	// 	game->c_count--;
	// }


}


int	key_hook(int key, t_game_info *game)
{
	if ((key == W_KEY || key == UP_KEY) && game->map[game->p_pos.y - 1][game->p_pos.x] != '1')
		events(game,0,-1);
		// game->p_pos.y--; // update
	else if ((key == S_KEY || key == DOWN_KEY) && game->map[game->p_pos.y + 1][game->p_pos.x] != '1')
		events(game,0,1);
	else if ((key == A_KEY || key ==LEFT_KEY) && game->map[game->p_pos.y][game->p_pos.x - 1] != '1')
		events(game,-1,0);
	else if ((key == D_KEY || key == RIGHT_KEY )&& game->map[game->p_pos.y][game->p_pos.x + 1] != '1')
		events(game,+1,0);
	// else if (key == ESC_KEY)
	// 	game->p_pos.x++;

}

// int hooks(t_game_info	*game)
// {
// }

int main(int ac, char **av)
{
	t_game_info	*game;

	if (ac == 1)
		ft_errors_exit(ERROR_3);
	if (ac > 2)
		ft_errors_exit(ERROR_6);
	if (ac == 2)
	{
		game = so_long(av);
		game->map[game->p_pos.y][game->p_pos.x] = '0';
		game->mlx = mlx_init();
		game->mlx_win = mlx_new_window(game->mlx, TILE * game->length , TILE * game->width, "so_long"); // we gotta do res
		load_textures(game);
		mlx_loop_hook(game->mlx, draw_map, game);
		mlx_key_hook(game->mlx_win,key_hook,game);
		// mlx_hook(game->mlx_win,02,0L,hooks,game);
		// mlx_hook();
				//catching hoooks
				// 

		// mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
		mlx_loop(game->mlx);
	}
}
