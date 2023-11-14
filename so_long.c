#include "so_long.h"


void	*jadarmi(void *mlx_ptr, char *filename, int *width, int *height)
{
	void *p;

	p = NULL;
	p = mlx_xpm_file_to_image(mlx_ptr, filename, width, height);
	if (!p)
		return (NULL);
	return (p);
}

void	*load_textures(t_game_info *game) // bool 
{
	game->textures.player_img = jadarmi(game->mlx, PLAYER_PATH, &game->textures.img_width, &game->textures.img_height); // missing handle error
	game->textures.coin_img = jadarmi(game->mlx, coin_path, &game->textures.img_width, &game->textures.img_height);
	game->textures.exit_img = jadarmi(game->mlx, exit_path, &game->textures.img_width, &game->textures.img_height);
	game->textures.floor_img = jadarmi(game->mlx, floor_path, &game->textures.img_width, &game->textures.img_height); // prottect against  null
	game->textures.wall_img = jadarmi(game->mlx, wall_path, &game->textures.img_width, &game->textures.img_height);
	// if (game->textures.coin_img)
	return (NULL);
}

void	free_textures(struct s_img_data *textures) //for now
{
		free(textures->floor_img);
		free(textures->wall_img);
		free(textures->coin_img);
		free(textures->exit_img);
		free(textures->player_img);
}

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


int  colision(char c)
{
	if (c == '1' || c == 'E')
		return (1);
	else if (c == 'C')
		return (3);
	else
		return(0);
}



void player_move(t_game_info *game , int x, int y) 
{
	// after move was authorized
	if (game->map[game->p_pos.y + y][game->p_pos.x + x] == 'C' )
	{
		game->c_count--;
		game->exit_allowed = (game->c_count == 0);
		game->map[game->p_pos.y + y][game->p_pos.x + x] = '0';
		fprintf(stderr,"coins left = %d  ",game->c_count);
	}
	if (game->map[game->p_pos.y + y][game->p_pos.x + x] == 'E' && game->exit_allowed == true)
		ft_errors_exit("Win Mutha Sucka");
	// if (game->exit_allowed == true &&)
		game->p_pos.x += x;
		game->p_pos.y += y;

}
/*
	int  y = (key == up) * (-1) + (key == down);
	int  x = (key == left) * (-1) + (key == right);
	if (playerp[py + y][px + x] != '1'){
		
	}
	zellllboooouz
*/

int	check_collision(char c, t_game_info *game)
{
	if (c == '1')
		return (false);
	if (c == 'E' && !(game->exit_allowed))
		return (false);
	return (true);
}

int	key_hook(int key, t_game_info *game) // handling keybord in put as well as wall colision
{



	if ((key == W_KEY) && check_collision(game->map[game->p_pos.y - 1][game->p_pos.x], game))
		player_move(game,0,-1);
	else if ((key == S_KEY) && check_collision(game->map[game->p_pos.y + 1][game->p_pos.x], game))
		player_move(game,0,1);
	else if ((key == A_KEY) &&  check_collision(game->map[game->p_pos.y][game->p_pos.x - 1], game))
		player_move(game,-1,0);
	else if ((key == D_KEY) &&  check_collision(game->map[game->p_pos.y][game->p_pos.x + 1], game))
		player_move(game,+1,0);
	
	// else if (key == ESC_KEY)
	// 	game->p_pos.x++;
}

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
		// mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
		mlx_loop(game->mlx);
		free(load_textures);
	}
}
