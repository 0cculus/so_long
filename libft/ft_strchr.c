/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:38:23 by brheaume          #+#    #+#             */
/*   Updated: 2022/10/21 09:46:26 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int find)
{
	int	i;
	int	src_len;

	i = 0;
	src_len = ft_strlen((char *)src);
	while (i <= src_len)
	{
		if ((unsigned char)src[i] == (unsigned char)find)
			return ((char *)src + i);
		i++;
	}
	return (0);
}
