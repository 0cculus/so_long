/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:39:25 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/25 13:06:43 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_images(t_data *game)
{
	game->images.wall = ft_texture_load(game->mlx, WALL);
	game->images.hero = ft_texture_load(game->mlx, HERO);
	game->images.floor = ft_texture_load(game->mlx, FLOOR);
	game->images.enemy = ft_texture_load(game->mlx, ENEMY);
	game->images.collect = ft_texture_load(game->mlx, COLLECT);
	game->images.exit_open = ft_texture_load(game->mlx, EXIT_OPEN);
	game->images.exit_close = ft_texture_load(game->mlx, EXIT_CLOSED);
}

static void	ft_init_game(t_data *game, int width, int height)
{
	game->score = 0;
	game->is_open = 0;
	game->nb_moves = 0;
	game->nb_collect = 0;
	game->mlx = mlx_init(width * SPRITE_SIZE, height * SPRITE_SIZE,
			"Frog: The Return of Minitalk", false);
	ft_init_images(game);
}

static void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*game;

	game = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
			ft_error_interrupt(game);
		else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			ft_move_vert(game, UP);
		else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			ft_move_vert(game, DOWN);
		else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			ft_move_horiz(game, LEFT);
		else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			ft_move_horiz(game, RIGHT);
	}
}

int	main(int ac, char **av)
{
	static t_data	game;
	char			**map;

	if (ac != 2)
		map = ft_loadmap("maps/base.ber");
	else
	{
		if (ft_verify_str(av[1]))
			map = ft_loadmap(av[1]);
		else
			ft_error_path();
	}
	//if (ft_verify_map(map))
	//	ft_error_map(map);
	ft_init_game(&game, ft_get_width(map) - 1, ft_get_height(map));
	game.map = map;
	game.nb_collect = ft_count_collectible(&game);
	ft_map_draw(&game);
	mlx_key_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
