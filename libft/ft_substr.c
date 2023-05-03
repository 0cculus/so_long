/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:15:17 by brheaume          #+#    #+#             */
/*   Updated: 2022/11/11 11:17:52 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	size_t	src_len;

	if (!s)
		return (0);
	src_len = ft_strlen(s);
	i = 0;
	while (i < len && s[i])
		i++;
	len = i;
	res = ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (0);
	if (start >= src_len)
		return (res);
	i = 0;
	while ((start + i) < src_len && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}
