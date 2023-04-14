/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:26:20 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/14 14:42:41 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_path(char *message)
{
	ft_putendl_fd(message, 0);
	return (EXIT_FAILURE);
}

int	ft_error_map(char **map, char *message)
{
	ft_cleararray(map);
	ft_putendl_fd(message, 0);
	return (EXIT_FAILURE);
}

// WIP
int ft_error_game(t_game *game, char *message)
{
	ft_cleararray(map);
	mlx_terminate();
}
