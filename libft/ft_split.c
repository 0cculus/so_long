/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:04:54 by brheaume          #+#    #+#             */
/*   Updated: 2022/11/15 14:03:42 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbword(const char *s, const char c)
{
	size_t	i;
	size_t	nb;
	size_t	is_sep;

	is_sep = 1;
	nb = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			is_sep = 1;
		else if (s[i] != c && is_sep)
		{
			is_sep = 0;
			nb++;
		}
		i++;
	}
	return (nb);
}

static char	*ft_explode(const char *s, size_t current, size_t len)
{
	size_t	i;
	char	*res;

	res = ft_calloc(sizeof(char), len - current + 1);
	if (!res)
		return (0);
	i = 0;
	while (current < len)
		res[i++] = s[current++];
	return (res);
}

static char	**ft_fsplit(char **res, const char *s, char c)
{
	long	i;
	size_t	j;
	long	len;
	long	start;

	start = -1;
	len = (long)ft_strlen(s);
	i = -1;
	j = 0;
	while (++i <= len)
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == len) && start >= 0)
		{
			res[j++] = ft_explode(s, start, i);
			start = -1;
		}
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;

	if (!s)
		return (0);
	res = malloc(sizeof(char *) * (ft_nbword(s, c) + 1));
	if (!res)
		return (0);
	res = ft_fsplit(res, s, c);
	return (res);
}
