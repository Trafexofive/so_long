

#include "so_long.h"


int main(void)
{
	int		i;
	char	*line;
	int		fd;
	t_map_count	map_info;

	fd = open("./maps/map1.ber", O_RDONLY);
	i = 0;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		while (line[i])
		{
			if (line[i] == 'P')
				map_info.player = map_info.player + 1;
			else if (line[i] == '1')
				map_info.wall = map_info.wall + 1;
			else if (line [i] == '0')
				map_info.floor = map_info.floor + 1;
			else if (line[i] == 'E')
				map_info.exit = map_info.exit + 1;
			else if (line[i] == 'C')
				map_info.collectibles = map_info.collectibles + 1;
			i++;
		}
		i = 0;
		printf("data--> %d\n", map_info.floor);
	}
	return EXIT_SUCCESS;
}
