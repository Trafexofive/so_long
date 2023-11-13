/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 03:48:49 by mlamkadm          #+#    #+#             */
/*   Updated: 2023/11/13 03:49:57 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_errors(char *error_macro)
{
	ft_putstr_fd(error_macro, 1);
}

void	ft_errors_exit(char *error_macro)
{
	ft_putstr_fd(error_macro, 1);
	exit(1);
}

