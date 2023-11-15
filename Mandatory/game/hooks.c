/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:01:01 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/11/15 05:45:33 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	key_hook(int key, t_game_info *game)
{
	if ((key == W_KEY) && 
		check_collision(game->map[game->p_pos.y - 1][game->p_pos.x], game))
		player_move(game,0,-1);
	else if ((key == S_KEY) && 
		check_collision(game->map[game->p_pos.y + 1][game->p_pos.x], game))
		player_move(game,0,1);
	else if ((key == A_KEY) &&  
		check_collision(game->map[game->p_pos.y][game->p_pos.x - 1], game))
		player_move(game,-1,0);
	else if ((key == D_KEY) &&  
		check_collision(game->map[game->p_pos.y][game->p_pos.x + 1], game))
		player_move(game,+1,0);
	else if (key == ESC_KEY)
		free_all(game);
}

int	check_collision(char c, t_game_info *game)
{
	if (c == '1')
		return (FALSE);
	if (c == 'E' && !(game->exit_allowed))
		return (FALSE);
	return (TRUE);
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
	if (game->map[game->p_pos.y + y][game->p_pos.x + x] == 'C' )
	{
		game->c_count--;
		game->exit_allowed = (game->c_count == 0);
		game->map[game->p_pos.y + y][game->p_pos.x + x] = '0';
	}
	if (game->map[game->p_pos.y + y][game->p_pos.x + x] == 'E' && game->exit_allowed == TRUE)
		ft_exit("Win Mutha Sucka",2);
	game->p_pos.x += x;
	game->p_pos.y += y;
	ft_putnbr_fd(game->move_count++, 1);
	ft_putchar_fd('\n', 1);
}