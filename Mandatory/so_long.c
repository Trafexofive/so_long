/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:52:25 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/11/15 05:03:07 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

static	int file_format(char *map_name)
{
	size_t	map_name_len;
	int		fd;

	map_name_len = ft_strlen(map_name);
	if (strnstr(map_name, ".ber", map_name_len) == NULL)
		return (ft_errors_exit(ERROR_1,1), -1);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (ft_errors_exit(ERROR_1,2), -1);
	return (fd);
}

static void	open_window(t_game_info *game)
{
	unsigned int w;
	unsigned int h;

	h = 0;
	w = 0;
	h = game->width * TILE;
	w = game->length * TILE;

	if (w < 2980 || h < 1550)
	{
		game->mlx = mlx_init();
		game->mlx_win = mlx_new_window(game->mlx, w , h, "so_long");
		load_textures(game);
	}
	else
	{
		free(game->map);
		free(game);
		ft_errors_exit("Invalid Map : Map is too big\n", 1);
	}
}

void f()
{
	system("leaks so_long");
}

int main(int ac, char **av)
{
	t_game_info	*game;

	if (ac == 2)
	{
		game = parse(file_format(*(++av)));
		game->map[game->p_pos.y][game->p_pos.x] = '0';
		open_window(game);
		mlx_loop_hook(game->mlx, (void *)draw_map, game);
		mlx_key_hook(game->mlx_win, (void *)key_hook,game); 
		mlx_hook(game->mlx_win, 17, 0, free_all, game);
		atexit(f);
		mlx_loop(game->mlx);

	}
	ft_errors_exit(ERROR_6 , 1);

}
