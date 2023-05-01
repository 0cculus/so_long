/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:16:06 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/28 10:17:14 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_width(char **map)
{
	return (ft_strlen(map[FIRST_INDEX]) - 1);
}

int	ft_get_height(char **map)
{
	return (ft_arraylen(map));
}
