#include "so_long.h"

void	draw_map(void *mlx, void *mlx_win, t_game_info *game, t_img_data *textures)
{
	int	x;
	int	y;
	int i;
	int	j;
	char	**map;

	i = TILE;
	j = TILE;
	x = 0;
	y = 0;
	map = NULL;
	map = game->map;

	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == '1')
				mlx_put_image_to_window(mlx, mlx_win, textures->wall_img, j, i);
			if (map[x][y] == '0')
				mlx_put_image_to_window(mlx, mlx_win, textures->floor_img, j, i);
			if (map[x][y] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, textures->floor_img, j, i);
			if (map[x][y] == 'E')
			{
				mlx_put_image_to_window(mlx, mlx_win, textures->floor_img, j, i);
				mlx_put_image_to_window(mlx, mlx_win, textures->exit_img, j, i);
			}
			if (map[x][y] == 'C')
			{
				mlx_put_image_to_window(mlx, mlx_win, textures->floor_img, j, i);
				mlx_put_image_to_window(mlx, mlx_win, textures->coin_img, j, i);
			}
			j = j + TILE;
			y++;
			textures->tile_lenght++;
		}
		textures->tile_lenght = 0;
		i = i + TILE;
		j = TILE;
		y = 0;
		x++;
		textures->tile_width++;
	}

}

void	*load_textures(t_img_data *textures, void *mlx)
{
	int		img_width = 100;
	int		img_height = 100;

	textures->floor_img = mlx_xpm_file_to_image(mlx, floor_path, &img_width, &img_height);
	textures->wall_img = mlx_xpm_file_to_image(mlx, wall_path, &img_width, &img_height);
	textures->coin_img = mlx_xpm_file_to_image(mlx, coin_path, &img_width, &img_height);
	textures->exit_img = mlx_xpm_file_to_image(mlx, exit_path, &img_width, &img_height);
	return (0);
}

int main(int ac, char **av)
{
	void		*mlx;
	void		*mlx_win;


	t_game_info	*game;
	t_img_data	*textures;

	game = NULL;
	textures = (t_img_data *)malloc (sizeof(t_img_data));
	if (ac == 1)
		ft_errors_exit(ERROR_3);
	if (ac > 2)
		ft_errors_exit(ERROR_6);
	if (ac == 2)
		game = so_long(av);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	load_textures(textures, mlx);
	draw_map(mlx, mlx_win, game, textures);

	

	// mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
	mlx_loop(mlx);
	free(textures);
}
