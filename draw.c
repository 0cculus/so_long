/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:18:21 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/14 15:00:21 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw(t_game game, int x, int y, mlx_image_t *img)
{
	if (game.map[y][x] == WALL_VAL)
		ft_draw_terrain();
	else if (game.map[y][x] == FLOOR_VAL)
		ft_draw_terrain(game, x, y, img);
	else if (game.map[y][x] == HERO_VAL)
		ft_draw_superimposed(game, x, y, img);
	else if (game.map[y][x] == COLLECT_VAL)
		ft_draw_superimposed(game, x, y, img);
	else if (game.map[y][x] == EXIT_CLOSED_VAL)
		ft_draw_superimposed(game, x, y, img);
	else if (game.map[y][x] == EXIT_OPEN_VAL)
		ft_draw_superimposed(game, x, y, img);
}

void	ft_draw_terrain(mlx_t mlx, int x, int y, mlx_image_t *img)
{
	mlx_image_to_window(mlx, img, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	ft_draw_superimposed(t_game game, int x, int y, mlx_image_t *img)
{
	ft_draw_terrain(&game.mlx, x, y, &game.im);
	mlx_image_to_window(&game.mlx, &img, x * SPRITE_SIZE, y * SPRITE_SIZE);
}
