/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 03:48:49 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/11/15 02:12:53 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_errors(char *error_macro)
{
	ft_putstr_fd(error_macro, 2);
}

void	ft_errors_exit(char *error_macro , int ern)
{
	ft_putstr_fd(error_macro, 2);
	exit(ern);
}

void free2d(char **map) // to libft
{
	int i;
	i = 0;
	while (map[i])
	{
        free(map[i]);
		i++;
    }
    free(map);
}

