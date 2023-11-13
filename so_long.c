#include "so_long.h"

void	draw_map(void *mlx, void *mlx_win, void *img, char **map)
{
	int	x;
	int	y;
	int i;
	int	j;

	i = TILE;
	j = TILE;
	x = 0;
	y = 0;

	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == '1')
				mlx_put_image_to_window(mlx, mlx_win, img, j, i);
			if (map[x][y] == '0')
				mlx_put_image_to_window(mlx, mlx_win, img, j, i);
			if (map[x][y] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, img, j, i);
			if (map[x][y] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, img, j, i);
			j = j + TILE;
			y++;
		}
		i = i + TILE;
		j = TILE;
		y = 0;
		x++;
	}

}


int main(int ac, char **av)
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	t_game_info	*game;
	char		**map;
	char		*floor_path= "./textures/floor.xpm";
	int			img_width = 10000;
	int			img_height = 10000;

	game = NULL;
	if (ac == 1)
		ft_errors_exit(ERROR_3);
	if (ac > 2)
		ft_errors_exit(ERROR_6);
	if (ac == 2)
		game = so_long(av);
	map = game->map;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	img = mlx_xpm_file_to_image(mlx, floor_path, &img_width, &img_height);
	draw_map(mlx, mlx_win, img, map);

	
	if (img == NULL)
		ft_errors("NULL");
	// mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
	mlx_loop(mlx);
}
