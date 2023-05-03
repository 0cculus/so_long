/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:20:48 by brheaume          #+#    #+#             */
/*   Updated: 2022/10/27 09:20:49 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *sc, size_t n)
{
	const char	*src;
	char		*dest;

	dest = dst;
	src = sc;
	if (sc == 0 && dest == 0)
		return (0);
	if (sc > dst)
		return (ft_memcpy(dst, sc, n));
	while (n)
	{
		n--;
		dest[n] = src[n];
	}
	return (dest);
}
