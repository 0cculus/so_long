/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:03:24 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/25 13:18:26 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*ft_texture_load(mlx_t *mlx, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	image = mlx_new_image(mlx, SPRITE_SIZE, SPRITE_SIZE);
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

char	**ft_loadmap(char *path)
{
	char	**res;
	char	*added;
	int		ffs;

	if (path)
	{
		ffs = open(path, O_RDONLY);
		if (ffs < 0)
			ft_error_path();
		res = NULL;
		added = get_next_line(ffs);
		while (added)
		{
			res = ft_arrayjoin(res, added);
			added = ft_xfree(added);
			added = get_next_line(ffs);
		}
		added = ft_xfree(added);
		close(ffs);
		return (res);
	}
	return (NULL);
}
