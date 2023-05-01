/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:26:20 by brheaume          #+#    #+#             */
/*   Updated: 2023/05/01 10:19:31 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_simple(char *message)
{
	ft_putendl_fd("Error:", ERROR_OUTPUT);
	ft_putendl_fd(message, ERROR_OUTPUT);
	exit(EXIT_FAILURE);
}

void	ft_error_map(char **map)
{
	ft_clear_array(map);
	ft_putendl_fd("Error\nInvalid map content\n", ERROR_OUTPUT);
	exit(EXIT_FAILURE);
}

void	ft_error_game(t_data *game)
{
	ft_clear_array(game->map);
	mlx_terminate(game->mlx);
	ft_putendl_fd("Error\nGame did an oopsie daisy", ERROR_OUTPUT);
	exit(EXIT_FAILURE);
}

void	ft_error_interrupt(t_data *game)
{
	ft_clear_array(game->map);
	mlx_terminate(game->mlx);
	ft_putendl_fd("Interrupted!", ERROR_OUTPUT);
	exit(EXIT_FAILURE);
}
