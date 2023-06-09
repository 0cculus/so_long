/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:02:41 by brheaume          #+#    #+#             */
/*   Updated: 2023/03/09 13:28:52 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstrdigit(const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (!(src[i] <= '9' && src[i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}
