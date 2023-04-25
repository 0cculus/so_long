/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:54:10 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/24 14:42:50 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_arraylen(char **src)
{
	int	i;

	i = 0;
	if (src)
		while (src[i])
			i++;
	return (i);
}

char	**ft_arrayjoin(char **src, char *s)
{
	char	**res;
	int		i;
	int		len;

	len = ft_arraylen(src);
	res = ft_calloc(len + 2, sizeof(char *));
	i = 0;
	if (!s)
		return (src);
	if (src)
	{
		while (src[i])
		{
			res[i] = ft_strdup(src[i]);
			i++;
		}
	}
	res[i] = ft_strdup(s);
	ft_clear_array(src);
	return (res);
}

void	*ft_clear_array(char **src)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i])
		{
			src[i] = ft_xfree(src[i]);
			i++;
		}
		src = ft_xfree(src);
	}
	return (NULL);
}

int	ft_get_width(char **map)
{
	return (ft_strlen(map[FIRST_INDEX]));
}

int	ft_get_height(char **map)
{
	return (ft_arraylen(map));
}
