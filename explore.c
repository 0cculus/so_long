/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:12:07 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/28 09:38:31 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	ft_find_hero(char **map)
{
	t_pos	pos;
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == HERO_VAL)
			{
				pos.x = x;
				pos.y = y;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

char	**ft_array_copy(char **src)
{
	char	**res;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	res = ft_calloc(ft_arraylen(src) + 1, sizeof(char *));
	while (src[i])
	{
		res[i] = ft_strdup(src[i]);
		i++;
	}
	return (res);
}

void	ft_flood_fill(t_verify *verif, int x, int y)
{
	if (verif->map[y][x] == WALL_VAL || verif->map[y][x] == 'k')
		return ;
	else if (verif->map[y][x] == HERO_VAL)
	{
		verif->hero_count++;
		verif->map[y][x] = 'k';
	}
	else if (verif->map[y][x] == COLLECT_VAL)
	{
		verif->collect_count++;
		verif->map[y][x] = 'k';
	}
	else if (verif->map[y][x] == EXIT_CLOSED_VAL)
	{
		verif->exit_count++;
		verif->map[y][x] = 'k';
	}
	else if (verif->map[y][x] == FLOOR_VAL)
		verif->map[y][x] = 'k';
	ft_flood_fill(verif, x + 1, y);
	ft_flood_fill(verif, x - 1, y);
	ft_flood_fill(verif, x, y + 1);
	ft_flood_fill(verif, x, y - 1);
}
