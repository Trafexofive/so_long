/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:52:13 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/11/15 04:59:52 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_textures(t_game_info *game)
{
	mlx_destroy_image(game->mlx, game->textures.player_img);
	mlx_destroy_image(game->mlx, game->textures.coin_img);
	mlx_destroy_image(game->mlx, game->textures.exit_img);
	mlx_destroy_image(game->mlx, game->textures.floor_img);
	mlx_destroy_image(game->mlx, game->textures.wall_img);
}


int	free_all(t_game_info *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_textures(game);
	free2d(game->map);
	free(game->mlx);
	free(game);
	ft_errors_exit("Quiting\n", 1);
	return (0);
}

void	*exit_texture(t_game_info *game)
{
	free2d(game->map);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mlx);
	free(game);
	ft_errors_exit(ERROR_11, 1);
	return (NULL);
}

void	*jadarmi(t_game_info   *game, char *filename)
{
	void	*p;
	
	p = mlx_xpm_file_to_image(game->mlx, filename, &game->textures.img_width, &game->textures.img_height);
	if (!p)
		return (exit_texture(game), NULL);
	return (p);
}

void	load_textures(t_game_info *game)
{
	game->textures.player_img = jadarmi(game, "textures/player.xpm");
	game->textures.coin_img = jadarmi(game, "textures/coin.xpm");
	game->textures.exit_img = jadarmi(game, "textures/exit.xpm");
	game->textures.floor_img = jadarmi(game, "textures/floor.xpm");
	game->textures.wall_img = jadarmi(game, "textures/wall.xpm");
}
