/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:18:21 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/27 11:08:01 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_draw_nonconcurrent(t_data *game, int x, int y, mlx_image_t *img)
{
	mlx_image_to_window(game->mlx, img, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	ft_draw_superimposed(t_data *game, int x, int y, mlx_image_t *img)
{
	ft_draw_nonconcurrent(game, x, y, game->images.floor);
	mlx_image_to_window(game->mlx, img, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

static void	ft_select_draw(t_data *game, int x, int y)
{
	if (game->map[y][x] == WALL_VAL)
		ft_draw_nonconcurrent(game, x, y, game->images.wall);
	else if (game->map[y][x] == FLOOR_VAL)
		ft_draw_nonconcurrent(game, x, y, game->images.floor);
	else if (game->map[y][x] == HERO_VAL)
		ft_draw_nonconcurrent(game, x, y, game->images.floor);
	else if (game->map[y][x] == COLLECT_VAL)
		ft_draw_superimposed(game, x, y, game->images.collect);
	else if (game->map[y][x] == EXIT_CLOSED_VAL)
	{
		game->x_exit = x;
		game->y_exit = y;
		ft_draw_superimposed(game, x, y, game->images.exit_close);
	}
}

void	ft_map_draw(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == HERO_VAL)
			{
				game->x_hero = x;
				game->y_hero = y;
				ft_draw_nonconcurrent(game, x, y, game->images.floor);
			}
			else
				ft_select_draw(game, x, y);
			x++;
		}
		y++;
	}
	if (BONUS)
		game->images.count = mlx_put_string(game->mlx, "0", \
			ft_get_width(game->map) * SPRITE_SIZE * 0.33, 21);
	ft_draw_nonconcurrent(game, game->x_hero, game->y_hero, game->images.hero);
}

void	ft_redraw_collect(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	mlx_delete_image(game->mlx, game->images.collect);
	game->images.collect = ft_texture_load(game->mlx, COLLECT);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == COLLECT_VAL)
				ft_draw_nonconcurrent(game, x, y, game->images.collect);
			x++;
		}
		y++;
	}
}
