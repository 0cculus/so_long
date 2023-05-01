/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:23:05 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/27 11:07:58 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_print_moves(t_data *game)
{
	char	*moves;

	if (!BONUS)
	{
		ft_putnbr_fd(game->nb_moves, TERM_OUTPUT);
		ft_putchar_fd('\n', TERM_OUTPUT);
	}
	else
	{
		mlx_delete_image(game->mlx, game->images.count);
		moves = ft_itoa(game->nb_moves);
		game->images.count = mlx_put_string(game->mlx, moves, \
				ft_get_width(game->map) * SPRITE_SIZE * 0.33, 21);
		moves = ft_xfree(moves);
	}
}

static void	ft_collect(t_data *game, int x, int y)
{
	if (game->map[y][x] == COLLECT_VAL)
	{
		game->map[y][x] = FLOOR_VAL;
		game->nb_collect--;
		if (!game->nb_collect)
		{
			mlx_delete_image(game->mlx, game->images.exit_close);
			game->map[game->y_exit][game->x_exit] = EXIT_OPEN_VAL;
			ft_draw_superimposed(game, game->x_exit, game->y_exit, \
					game->images.exit_open);
		}
		game->score++;
		ft_redraw_collect(game);
	}
}

static void	ft_complete(t_data *game, int x, int y)
{
	if (!game->nb_collect && game->map[y][x] == EXIT_OPEN_VAL)
	{
		ft_putendl_fd("CONGRATZZZZZ", TERM_OUTPUT);
		ft_clear_array(game->map);
		mlx_delete_image(game->mlx, game->images.hero);
		mlx_terminate(game->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	ft_move_vert(t_data *game, int direction)
{
	int	x;
	int	y;

	x = game->images.hero->instances[FIRST_INDEX].x / SPRITE_SIZE;
	y = game->images.hero->instances[FIRST_INDEX].y / SPRITE_SIZE;
	if (game->map[y + direction][x] && game->map[y + direction][x] != WALL_VAL)
	{
		y += direction;
		game->images.hero->instances[FIRST_INDEX].y += \
											(direction * SPRITE_SIZE);
		ft_collect(game, x, y);
		game->nb_moves++;
		ft_print_moves(game);
		ft_complete(game, x, y);
	}
}

void	ft_move_horiz(t_data *game, int direction)
{
	int	x;
	int	y;

	x = game->images.hero->instances[FIRST_INDEX].x / SPRITE_SIZE;
	y = game->images.hero->instances[FIRST_INDEX].y / SPRITE_SIZE;
	if (game->map[y][x + direction] && game->map[y][x + direction] != WALL_VAL)
	{
		x += direction;
		game->images.hero->instances[FIRST_INDEX].x += \
											(direction * SPRITE_SIZE);
		ft_collect(game, x, y);
		game->nb_moves++;
		ft_print_moves(game);
		ft_complete(game, x, y);
	}
}
