/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:12:40 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/11/15 05:53:54 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	flood_field(char **flooded_map, int x, int y)
{
	if (flooded_map[x][y] && flooded_map[x][y] != '1' &&
		flooded_map[x][y] != 'E' && flooded_map[x][y] != 'X')
	{
		flooded_map[x][y] = 'X';
		flood_field(flooded_map, x + 1, y);
		flood_field(flooded_map, x - 1, y);
		flood_field(flooded_map, x, y + 1);
		flood_field(flooded_map, x, y - 1);
	}
	if (flooded_map[x][y] == 'E')
		flooded_map[x][y] = 'X';
}

bool	valid_flow(char **map)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == 'C' || map[x][y] == 'E' || map[x][y] == 'P')
				return (FALSE);
			y++;
		}
		y = 1;
		x++;
	}
	return (TRUE);
}
