/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:54:10 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/14 09:29:07 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_arraylen(char **src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	**ft_arrayjoin(char **src, char *s)
{
	char	**res;
	int		i;

	res = ft_calloc(ft_arraylen(src), sizeof(char *));
	if (src)
	{
		while (src[i])
		{
			res[i] = src[i];
			i++;
		}
	}
	res[i] = s;
	ft_xfree(src);
	return (res);
}

void	*ft_cleararray(char **src)
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
