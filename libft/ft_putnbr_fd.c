/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:09:55 by brheaume          #+#    #+#             */
/*   Updated: 2022/11/04 09:59:12 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n != INT_MIN)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		if (n > 9)
		{
			c = (n % 10) + '0';
			ft_putnbr_fd(n /= 10, fd);
			write(fd, &c, 1);
		}
		else
		{
			c = n % 10 + '0';
			write(fd, &c, 1);
		}
	}
	else
		write(fd, "-2147483648", 11);
}
