/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:45:22 by brheaume          #+#    #+#             */
/*   Updated: 2022/10/20 15:20:39 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int find)
{
	int	i;

	i = ft_strlen((char *)src);
	while (i >= 0)
	{
		if ((unsigned char)src[i] == (unsigned char)find)
			return ((char *)src + i);
		i--;
	}
	return (0);
}
