/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:30:43 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/28 10:36:13 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verify_str(char *src)
{
	int		i;
	char	*ext;

	i = 0;
	ext = ft_strrchr(src, '.');
	if (ext && !ft_strncmp(ext, MAP_EXT, MAP_EXT_SIZE))
		return (CORRECT);
	return (INCORRECT);
}

int	ft_verify_walls(char **map)
{
	int	x;
	int	y;
	int	x_max;
	int	y_max;

	x = -1;
	y = -1;
	x_max = ft_get_width(map) - 1;
	y_max = ft_get_height(map) - 1;
	while (++x < x_max)
		if (map[FIRST_INDEX][x] != WALL_VAL)
			return (INCORRECT);
	x++;
	while (--x)
		if (map[y_max][x] != WALL_VAL)
			return (INCORRECT);
	while (++y < y_max)
		if (map[y][FIRST_INDEX] != WALL_VAL)
			return (INCORRECT);
	y++;
	while (--y)
		if (map[y][x_max] != WALL_VAL)
			return (INCORRECT);
	return (CORRECT);
}

int	ft_verify_maplength(char **map)
{
	int	i;
	int	len;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]) - 1;
		if (i > MAP_HEIGHT_MAX)
			return (INCORRECT);
		if (len > MAP_WIDTH_MAX)
			return (INCORRECT);
		if (len != ft_get_width(map))
			return (INCORRECT);
		i++;
	}
	return (CORRECT);
}

int	ft_verify_content(char **map)
{
	t_pos	pos;
	int		nb_hero;
	int		nb_exit;

	pos.y = 0;
	nb_exit = 1;
	nb_hero = 1;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == HERO_VAL)
				nb_hero--;
			if (map[pos.y][pos.x] == EXIT_CLOSED_VAL)
				nb_exit--;
			if (!ft_valid_value(map[pos.y][pos.x]))
				return (INCORRECT);
			pos.x++;
		}
		pos.y++;
	}
	if (nb_exit != 0 || nb_hero != 0)
		return (INCORRECT);
	return (CORRECT);
}

int	ft_verify_map(char **map)
{
	t_verify	verif;	
	t_pos		pos;
	int			nb_collect;

	ft_bzero(&verif, sizeof(verif));
	nb_collect = ft_count_collectible(map);
	if (ft_verify_maplength(map) && nb_collect > 0
		&& ft_verify_content(map) && ft_verify_walls(map))
	{
		pos = ft_find_hero(map);
		verif.map = ft_array_copy(map);
		ft_flood_fill(&verif, pos.x, pos.y);
		if (verif.hero_count == 1 && verif.exit_count == 1
			&& verif.collect_count == nb_collect)
		{
			verif.map = ft_clear_array(verif.map);
			return (CORRECT);
		}
		verif.map = ft_clear_array(verif.map);
	}
	return (INCORRECT);
}
