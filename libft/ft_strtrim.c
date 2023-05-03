/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:42:36 by brheaume          #+#    #+#             */
/*   Updated: 2022/11/15 14:02:52 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	char	*res;
	size_t	total;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	total = 0;
	if (!ft_strlen(set))
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_strrchr(set, s1[j -1]))
		j--;
	res = ft_calloc(j - i + 1, sizeof(char));
	if (!res)
		return (0);
	while (i < j)
		res[total++] = s1[i++];
	res[total] = '\0';
	return (res);
}
