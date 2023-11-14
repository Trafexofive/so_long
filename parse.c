#include "so_long.h"

bool	valid_map(char *buffered_map, t_game_info *game)
{
	int 		i;
	int 		j;
	char		**map;
	t_counter	objects;

	i = 1;
	j = 1;
	ft_bzero(&objects, sizeof(t_counter));
	map = ft_split(buffered_map, '\n');
	if (!map)
		return (free(game), free(map), FALSE);
	game->length = valid_walls (map[0]);
	if (game->length == -1)
		return (free(game), free(map), FALSE); // free map not surrounded by walls;

	while (map[i] && i < (game->width - 1))
	{
		if (map[i][0] != '1')
			return (FALSE); //not rectangulor
		// printf("%s\n",map[i]);
		while (map[i][j])
		{
			if (valid_element(map,i,j,&objects) == FALSE)
				return (FALSE);
			j++;
		}
		if (j != game->length || map[i][j - 1] != '1')// checking for the valid sides
			return (FALSE);
		j = 1;
		i++;

	}
	if (valid_walls(map[i]) == -1 || allowed_elements(&objects) == FALSE)
		return (FALSE);
	game->p_pos = objects.p_pos;
	game->c_count = objects.collectibles;
	game->e_pos = objects.e_pos;
	game->map = map;
	return (TRUE);
}

bool	valid_flow(char **map)
{
	int x = 1;
	int y = 1;

	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] ==  'C' || map[x][y] == 'E' || map[x][y] == 'P')
				return (FALSE);
			y++;
		}
		y = 1;
		x++;
	}
	return (TRUE);
}

void	flood_field(char **flooded_map, int x, int y)
{
	if (flooded_map[x][y] && flooded_map[x][y] != '1' && flooded_map[x][y] != 'E' && flooded_map[x][y] != 'X')
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

t_game_info	*so_long(char **av)
{
	char 		*map;
	t_game_info	*game;

	game = ft_calloc(sizeof(t_game_info), 1);
	if (!game)
		return (NULL);
	map = read_file(av[1], game);
	if (valid_map(map, game) == FALSE)
	{
		free(game);
		free(map);
		exit(1);
	}
	char **flooded_map = ft_split(map,'\n');
	flood_field(flooded_map, game->p_pos.x, game->p_pos.y);
	// for (size_t i = 0; flooded_map[i]; i++)
	// {
	// 	printf("%s\n", flooded_map[i]);
	// }
	if (valid_flow(flooded_map) == FALSE)
		return (NULL);
	return (game);

}

