/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 03:39:26 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/11/15 01:20:49 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	valid_walls(char *line , int *size)
{
	int i = 0;

	while (line[i] && line[i] == '1')
		i++;
	if (line[i] == '\0')
	{
		*size = i;
		return (i);
	}
	return (-1);
}

bool	valid_element(char **map, int i , int j , t_counter *elements)
{
	char c = map[i][j];

	if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
	{
		if (c == 'P')
		{
			elements->player++;
			elements->p_pos.x = i;
			elements->p_pos.y = j;
		}
		else if (c == 'C')
			elements->collectibles++;
		else if ( c == 'E')
		{
			elements->exit++;
			elements->e_pos.x = i; // del
			elements->e_pos.y = j; // del
		}
		return (TRUE);
	}
	return (FALSE);
}

bool allowed_elements(t_counter *elements)
{
	if (elements->player == 1 && elements->exit == 1 && elements->collectibles > 0)
		return(TRUE);
	return(FALSE);
}