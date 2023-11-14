/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 03:39:26 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/11/14 15:05:16 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(char *map_name, t_game_info *data)
{
	char	*line;
	char 	*tmp;
	size_t	map_name_len;
	int		fd;

	map_name_len = ft_strlen(map_name);
	if (strnstr(map_name, ".ber", map_name_len) == NULL)
	{
		free(data);
		ft_errors_exit(ERROR_1);
	}
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		free(data);
		ft_errors_exit(ERROR_1);
	}
	tmp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if(*line == '\n')
			return(printf("exit"),exit(1),NULL);
			//error + free + exit
		data->width++;
		tmp = ft_strjoin(tmp, line);	// leaks protect in case
	}
	return (tmp);
}

int	valid_walls(char *line)
{
	int i = 0;

	while (line[i] && line[i] == '1')
		i++;
	if (line[i] == '\0')
		return (i);
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
			elements->e_pos.x = i;
			elements->e_pos.y = j;
		}
		return (true);
	}
	return (false);
		
}

bool allowed_elements(t_counter *elements)
{
	if (elements->player == 1 && elements->exit == 1 && elements->collectibles > 0)
		return(true);
	return(false);
}