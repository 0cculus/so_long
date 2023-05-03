/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:10:54 by brheaume          #+#    #+#             */
/*   Updated: 2022/11/04 10:52:27 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *src)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (src[i] && (src[i] == 32 || (src[i] >= 9 && src[i] <= 13)))
		i++;
	if (src[i] == '-' || src[i] == '+')
	{
		if (src[i] == '-')
			neg *= -1;
		i++;
	}
	while (src[i] >= '0' && src[i] <= '9')
	{
		res *= 10;
		res += (src[i] - '0');
		i++;
	}
	return (neg * res);
}
