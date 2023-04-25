/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:57:50 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/25 13:12:22 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# include <fcntl.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# ifndef SPRITE_SIZE
#  define SPRITE_SIZE 60
# endif
# ifndef ERROR_OUTPUT
#  define ERROR_OUTPUT 2
# endif
# ifndef TERM_OUTPUT
#  define TERM_OUTPUT 1
# endif
# ifndef BONUS
#  define BONUS 0
# endif

# define MOVE 60
# define RIGHT 1
# define LEFT -1
# define UP -1
# define DOWN 1
# define CORRECT 1
# define INCORRECT 0
# define FIRST_INDEX 0 

# define MAP_EXT ".ber"
# define MAP_EXT_SIZE 4
# define MAP_HEIGHT_MAX 22
# define MAP_WIDTH_MAX 42

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
# define COLLECT "./assets/collectible.png"
# define HERO "./assets/frog.png"
# define EXIT_CLOSED "./assets/computer_closed.png"
# define EXIT_OPEN "./assets/computer_open_exit.png"
# define ENEMY "./assets/enemy.png"

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
	mlx_t	*mlx;
	t_img	images;
	int		score;
	int		x_exit;
	int		y_exit;
	int		is_open;
	int		nb_moves;
	int		nb_collect;
	char	**map;
}	t_data;

int			ft_arraylen(char **src);
int			ft_get_width(char **map);
int			ft_verify_str(char *src);
int			ft_verify_map(char **map);
int			ft_get_height(char **map);
int			ft_verify_walls(char **src);
int			ft_count_collectible(t_data *game);

void		ft_error_path(void);
void		ft_error_map(char **map);
void		ft_map_draw(t_data *game);
void		ft_error_game(t_data *game);
void		*ft_clear_array(char **src);
void		ft_redraw_collect(t_data *game);
void		ft_error_interrupt(t_data *game);
void		ft_move_vert(t_data *game, int direction);
void		ft_move_horiz(t_data *game, int direction);
void		ft_draw_superimposed(t_data *game, int x, int y, mlx_image_t *mlx);

char		**ft_loadmap(char *path);
char		**ft_arrayjoin(char **src, char *s);
mlx_image_t	*ft_texture_load(mlx_t *mlx, char *path);

#endif
