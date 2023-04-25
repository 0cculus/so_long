/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:30:43 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/25 16:00:43 by brheaume         ###   ########.fr       */
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
	int len;

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

int	ft_verify_map(char **map)
{
	int	nb_collect;

	nb_collect = ft_count_collectible(map);
	if (ft_verify_maplength(map) && nb_collect > 0
			/*&& ft_verify_content(map)*/ && ft_verify_walls(map))
		return (CORRECT);
	return (INCORRECT);
}
