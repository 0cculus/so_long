/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:57:50 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/14 14:58:08 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# include <fcntl.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# ifndef SPRITE_SIZE
#  define SPRITE_SIZE 60
# endif

#  define MOVE 60
# define RIGHT 1
# define LEFT -1
# define UP -1
# define DOWN 1
# define CORRECT 1
# define INCORRECT 0
# define FIRST_INDEX 0 

# define MAP_EXT ".ber"
# define MAP_EXT_SIZE 4

# define WALL_VAL '1'
# define FLOOR_VAL '0'
# define COLLECT_VAL 'C'
# define HERO_VAL 'P'
# define EXIT_CLOSED_VAL 'E'
# define EXIT_OPEN_VAL 'O'
# define ENEMY_VAL 'K'

# define BASE_MAP_PATH "./maps/base.ber"
# define FLOOR "./assets/floor.png"
# define WALL "./assets/wall.png"
# define COLLECT "./assets/collection.png"
# define HERO "./assets/frog.png"
# define EXIT_CLOSED "./assets/computer_closed.png"
# define EXIT_OPEN "./assets/computer_open_exit.png"
# define ENEMY "./assets/enemy.png"

# define WIDTH 1024
# define HEIGHT 512

typedef struct s_img
{
	mlx_image_t	*wall;
	mlx_image_t	*hero;
	mlx_image_t	*floor;
	mlx_image_t	*enemy;
	mlx_image_t	*collect;
	mlx_image_t	*exit_open;
	mlx_image_t	*exit_close;
}	t_img;

typedef struct s_data
{
	mlx_t	mlx;
	t_img	images;
	int		x_hero;
	int		y_hero;
	int		is_open;
	int		nb_moves;
	int		nb_collect;
}	t_data;

int		ft_arraylen(char **src);
int		ft_verify_str(char *src);
int		ft_verify_walls(char **src, int x_max, int y_max);
void	ft_cleararray(char **src);
void	ft_draw(t_data game, int x, int y, mlx_image_t img);
void	ft_draw_superimposed(t_data game, int x, int y, mlx_image_t img);
void	ft_draw_terrain(t_data game, int x, int y, mlx_image_t img);
char	**ft_loadmap(char *path);
char	**ft_arrayjoin(char **src, char *s);

#endif
