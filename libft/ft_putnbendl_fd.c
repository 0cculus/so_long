/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbendl_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:28:42 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/25 14:34:28 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbendl_fd(int nb, int fd)
{
	ft_putnbr_fd(nb, fd);
	ft_putchar_fd('\n', fd);
}
