/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:30:43 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/14 14:58:20 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verify_str(char *src)
{
	int		i;
	char	*ext;

	i = 0;

	ext = ft_strrstr(src, '.');
	if (ext && !ft_strncmp(ext, MAP_EXT, MAP_EXT_SIZE))
		return (CORRECT);
	return (INCORRECT);
}

int	ft_verify_walls(char **map, int x_max, int y_max)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
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
	return (CORRECT);
}

int	ft_verify_map(char **map)
{
	return (CORRECT);
}
