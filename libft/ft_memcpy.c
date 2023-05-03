/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:20:36 by brheaume          #+#    #+#             */
/*   Updated: 2022/10/27 09:20:37 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *sc, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*src;

	dest = dst;
	src = sc;
	i = 0;
	if (src == dest)
		return (dest);
	while (n)
	{
		n--;
		dest[i] = src[i];
		i++;
	}
	return ((void *)dest);
}
