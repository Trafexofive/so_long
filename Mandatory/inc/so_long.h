/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:56:12 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/11/15 05:32:09 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <mlx.h>
# include <stdbool.h>
# include "./defines.h"
# include "../../libft/libft.h"

t_game_info	*parse(int fd);
void		ft_errors_exit(char *error_macro , int ern);
void 		free2d(char **map); // to libft
void		ree_textures(t_game_info *game);
void		ft_errors(char *error_macro);
int			free_all(t_game_info *game);

bool		allowed_elements(t_counter *elements);
bool		valid_element(char **map, int i , int j , t_counter *elements);

bool		valid_flow(char **map);
void		flood_field(char **flooded_map, int x, int y);

int			valid_walls(char *line , int *size);


void		key_hook(int key, t_game_info *game);
int			check_collision(char c, t_game_info *game);
int 		colision(char c);
void		player_move(t_game_info *game , int x, int y); 

void		load_textures(t_game_info *game);
void		draw_map(t_game_info *game);

#endif
