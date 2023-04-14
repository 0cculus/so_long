/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:39:25 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/14 09:45:41 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	ft_init_imgs(mlx_t *mlx)
{
	t_img	imgs;

	imgs.wall = ft_texture_load(mlx, WALL);
	imgs.hero = ft_texture_load(mlx, HERO);
	imgs.floor = ft_texture_load(mlx, FLOOR);
	imgs.enemy = ft_texture_load(mlx, ENEMY);
	imgs.collect = ft_texture_load(mlx, COLLECT);
	imgs.exit_open = ft_texture_load(mlx, EXIT_OPEN);
	imgs.exit_close = ft_texture_load(mlx, EXIT_CLOSED);
	return (imgs);
}

static t_data	ft_init_game(int width, int height)
{
	t_data	game;

	game.x_hero = 0;
	game.y_hero = 0;
	game.is_open = 0;
	game.nb_moves = 0;
	game.nb_collect = 0;
	game.mlx = mlx_init(width height, "Frog: The Return of Minitalk", false);
	game.images = ft_init_imgs(&game.mlx);
	return (game);
}

static void	ft_hook(void* param)
{
	t_data	*game;

	game = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE)
		|| mlx_is_key_down(mlx, MLX_KEY_Q))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP)
		|| mlx_is_key_down(mlx, MLX_KEY_W))
		ft_movevert(game->images.hero->instances[0].y, UP);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(mlx, MLX_KEY_S))
		ft_movevert(game->images.hero->instances[0].y, DOWN);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(mlx, MLX_KEY_A))
		ft_movehoriz(game->images.hero->instances[0].y, LEFT);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(mlx, MLX_KEY_D))
		ft_movehoriz(game->images.hero->instances[0].y, RIGHT);
}

int	main(int ac, char **av)
{
	static t_data	game;
	char			**map;
	
	if (ac != 2)
		map = ft_loadmap("maps/base.ber");
	else
	{
		if (ft_verifystr(av[1]))
			map = ft_loadmap(av[1]);
		else
			return (ft_error_path("Bad map path\n"));
	}
	game = ft_init_game(ft_get_width(map), ft_get_height(map));
	if (!game)
		return (ft_error_game("Game failed\n"));
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
