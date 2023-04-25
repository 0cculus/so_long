/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:26:20 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/25 12:32:21 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_path(void)
{
	ft_putendl_fd("Invalid map path\n", ERROR_OUTPUT);
	exit(EXIT_FAILURE);
}

void	ft_error_map(char **map)
{
	ft_clear_array(map);
	ft_putendl_fd("Invalid map\n", ERROR_OUTPUT);
	exit(EXIT_FAILURE);
}

void	ft_error_game(t_data *game)
{
	ft_clear_array(game->map);
	mlx_terminate(game->mlx);
	ft_putendl_fd("Game did an oopsie daisy", ERROR_OUTPUT);
	exit(EXIT_FAILURE);
}

void	ft_error_interrupt(t_data *game)
{
	ft_clear_array(game->map);
	mlx_terminate(game->mlx);
	ft_putendl_fd("Interrupted!", ERROR_OUTPUT);
	exit(EXIT_FAILURE);
}
