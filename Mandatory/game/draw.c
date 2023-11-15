/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:51:12 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/11/15 05:59:27 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_map(t_game_info *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window (game->mlx,game->mlx_win);
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, 
					game->textures.wall_img, TILE * j , TILE * i);
			else if (game->map[i][j] == '0' || game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, 
					game->textures.floor_img, TILE * j, TILE * i);
			else if (game->map[i][j] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, 
					game->textures.floor_img, TILE * j, TILE * i);
				mlx_put_image_to_window(game->mlx, game->mlx_win, 
					game->textures.coin_img, TILE * j, TILE * i);
			}
			else if (game->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, 
					game->textures.floor_img, TILE * j, TILE * i);
				mlx_put_image_to_window(game->mlx, game->mlx_win, 
					game->textures.exit_img, TILE * j, TILE * i);
			}
			j++;
		}
		i++;
		j = 0;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->textures.player_img, TILE * game->p_pos.x, TILE * game->p_pos.y);
}
