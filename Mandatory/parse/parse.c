/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:54:28 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/11/15 05:13:16 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	*strjoinem(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	full_len;
	char	*full_str;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	full_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	full_str = (char *)malloc(full_len * sizeof(char));
	if (!full_str)
		return (NULL);
	while (s1[i] && i < full_len)
	{
		full_str[i] = s1[i];
		i++;
	}
	while (s2[j] && i < full_len)
		full_str[i++] = s2[j++];
	full_str[i] = '\0';
	free(s1);
	return (full_str);
}

static char		*read_file(t_game_info *game , int fd)
{
	char	*line;
	char 	*tmp2;

	tmp2 = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if(*line == '\n')
			return (free(line),free(game),close(fd),ft_errors_exit(ERROR_8, 1),NULL);
		tmp2 = strjoinem(tmp2, line);
		free(line);
		line = NULL;
		game->width++;
	}
	return (tmp2);
}

static bool		valid_map(char **map, t_game_info *game)
{
	int 		i;
	int 		j;
	t_counter	objects;

	i = 1;
	j = 1;
	ft_bzero(&objects, sizeof(t_counter));
	if (valid_walls (map[0] , &game->length) == -1)
		return (FALSE);
	while (map[i] && i < (game->width - 1))
	{
    	if (map[i][0] != '1')
        	return (free(game), free2d(map), FALSE);
    	while (map[i][j])
    	{
    	    if (valid_element(map,i,j,&objects) == FALSE)
    	        return (FALSE);
    	    j++;
    	}
    	if (j != game->length || map[i][j - 1] != '1')
    	    return (FALSE);
    	j = 1;
    	i++;
	}
	if (valid_walls (map[i] , &j) == -1 || allowed_elements(&objects) == FALSE)
		return (FALSE);
	game->p_pos = objects.p_pos;
	game->c_count = objects.collectibles;
	game->e_pos = objects.e_pos;
	game->map = map;
	return (TRUE);
}

t_game_info	*parse(int fd)
{
	char 		*map;
	char 		**flooded_map;
	t_game_info	*game;

	game = ft_calloc(sizeof(t_game_info), 1);
	if (!game)
		return (NULL);
	map = read_file(game, fd);
	close (fd);
	flooded_map = ft_split(map, '\n');
	if (!flooded_map)
	    return (free(game), ft_errors_exit(ERROR_10, 1), NULL);
	if (valid_map(flooded_map, game) == FALSE)
		return (free2d(flooded_map),free(map),free(game), ft_errors_exit(ERROR_9, 1),NULL);
	flooded_map = NULL;
	flooded_map = ft_split(map,'\n');
	free(map);
	if (!flooded_map)
	    return (free2d(game->map),free(game), ft_errors_exit(ERROR_10, 1),NULL);
	flood_field(flooded_map, game->p_pos.x, game->p_pos.y);
	if (valid_flow(flooded_map) == FALSE)
		return(free2d(flooded_map),free2d(game->map),free(game),ft_errors_exit(ERROR_5, 1),NULL);
	return (free2d(flooded_map), game);
}

