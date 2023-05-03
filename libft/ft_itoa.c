/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:38:56 by brheaume          #+#    #+#             */
/*   Updated: 2022/11/15 14:04:59 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbdigit(int n)
{
	size_t	nb;

	nb = 0;
	if (n < 0)
	{
		nb++;
		n *= -1;
	}
	while (n > 9)
	{
		nb++;
		n /= 10;
	}
	nb++;
	return (nb);
}

static char	*ft_fitoa(char *res, size_t len, int n)
{
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	len--;
	while (n > 9)
	{
		res[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	res[len] = n % 10 + '0';
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*res;

	if (n > INT_MAX)
		return (0);
	else if (n < INT_MIN)
		return (0);
	else if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_nbdigit(n);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	res = ft_fitoa(res, len, n);
	return (res);
}
