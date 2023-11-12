#include "so_long.h"

void	ft_errors(char *error_macro)
{
	ft_putstr_fd(error_macro, 1);
	exit(1);
}

char	*read_file(char *map_name, t_game_info *data)
{
	char	*line;
	char 	*tmp;
	size_t	map_name_len;

	map_name_len = ft_strlen(map_name);
	if (strnstr(map_name, ".ber", map_name_len) == NULL) // .bers
		ft_errors(ERROR_1);
	int fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_errors(ERROR_2);
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
			elements->exit++;
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

bool	valid_map(char *buffered_map, t_game_info *game)
{
	// if map not valid free alll the shit
	int i = 1;
	int j = 1;
	char	**map;
	t_counter elemts;

	bzero(&elemts,sizeof(t_counter));
	map = ft_split(buffered_map, '\n');
	if (!map)
		return (false);
	game->length = valid_walls (map[0]);
	if (game->length == -1)
		return (fprintf(stderr,"%d",1),false); // free map not surrounded by walls;

	while (map[i] && i < (game->width - 1))
	{
		if (map[i][0] != '1')
			return (fprintf(stderr,"%d",2),false); //not rectangulor
		// printf("%s\n",map[i]);
		while (map[i][j])
		{
			if (valid_element(map,i,j,&elemts) == false)
				return (fprintf(stderr,"%d",3),false);
			j++;
		}
		if (j != game->length || map[i][j - 1] != '1')// checking for the valid sides
			return (fprintf(stderr,"c == %d\n",4),false);
		j = 1;
		i++;

	}
	if (valid_walls(map[i]) == -1 || allowed_elements(&elemts) == false)
		return (fprintf(stderr,"%d == %d %d %d\n",5,elemts.collectibles,elemts.exit,elemts.player),false);
	game->p_pos = elemts.p_pos;
	game->c_count = elemts.collectibles;
	game->map = map;
	return (true);
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
				return (false);
			y++;
		}
		y = 1;
		x++;
	}
	return (true);
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

void	*so_long(char **av)
{
	char 		*map;
	t_game_info	*game;

	game = ft_calloc(sizeof(t_game_info), 1);
	if (!game)
		return (NULL);
	
	map = read_file(av[1], game);
	if (valid_map(map, game) == false)
	{
		//free error 
		exit(11);
	}
	char **flooded_map = ft_split(map,'\n');
	flood_field(flooded_map, game->p_pos.x, game->p_pos.y);
	for (size_t i = 0; flooded_map[i]; i++)
	{
		printf("%s\n", flooded_map[i]);
	}
	if (valid_flow(flooded_map) == false)
		return (NULL);

	
}

int main(int ac, char **av)
{
	if (ac == 2)
		so_long(av);
	else
		ft_errors(ERROR_3);
	// no map provided
	return EXIT_FAILURE;
}
