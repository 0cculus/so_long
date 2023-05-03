/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:10:50 by brheaume          #+#    #+#             */
/*   Updated: 2022/10/24 09:10:51 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len < 0)
		return ((char *)hay);
	if (!needle[i])
		return ((char *)hay);
	while (i < len && hay[i])
	{
		j = 0;
		if (hay[i] == needle[j])
		{
			while (hay[i + j] == needle[j] && i + j < len)
			{
				if (!needle[j + 1])
					return ((char *)hay + i);
				j++;
			}
		}
		i++;
	}
	return (0);
}
