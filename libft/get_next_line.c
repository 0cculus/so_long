/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:22:02 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/11 13:21:28 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_isreturnline(const char *src)
{
	int	i;

	i = 0;
	while (src[i])
		if (src[i++] == '\n')
			return (1);
	return (0);
}

int	gnl_atin(const char *src, const char c)
{
	int	i;

	i = 0;
	if (src)
		while (src[i] != c && src[i])
			i++;
	return (i);
}

char	*gnl_substr(char *src, size_t *len)
{
	size_t	i;
	char	*res;

	i = 0;
	while (i < *len && src[i])
		i++;
	*len = i;
	res = gnl_calloc(sizeof(char), (*len + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < *len)
	{
		res[i] = src[i];
		i++;
	}
	return (res);
}

char	*gnl_read(char *res, char *current, int *rv, const int fd)
{
	while (!gnl_isreturnline(res))
	{
		gnl_bzero(current, BUFFER_SIZE + 1);
		*rv = read(fd, current, BUFFER_SIZE);
		if (*rv <= 0)
			break ;
		res = gnl_strjoin(res, current);
	}
	current = gnl_xfree(current);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*tmp2;
	char		*tmp;
	size_t		rm;
	int			rv;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (store = gnl_xfree(store));
	if (!store)
		store = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	tmp = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	store = gnl_read(store, tmp, &rv, fd);
	if (rv == -1 || (!rv && !store[0]))
	{
		store = gnl_xfree(store);
		return (store);
	}
	rm = gnl_atin(store, '\n') + 1;
	tmp = gnl_substr(store, &rm);
	tmp2 = store;
	store = gnl_strjoin(NULL, store + rm);
	gnl_xfree(tmp2);
	return (tmp);
}
