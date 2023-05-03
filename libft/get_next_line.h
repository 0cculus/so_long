/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brheaume <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:19:03 by brheaume          #+#    #+#             */
/*   Updated: 2023/04/11 16:50:52 by brheaume         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 120
# endif

void	*gnl_xfree(char *src);
char	*get_next_line(int fd);
size_t	gnl_strlen(const char *src);
int		gnl_isreturnline(const char *c);
void	gnl_bzero(void *src, size_t len);
char	*gnl_substr(char *src, size_t *len);
char	*gnl_strjoin(char *s1, const char *s2);
int		gnl_atin(const char *src, const char c);
void	*gnl_calloc(unsigned int size, unsigned int count);
char	*gnl_read(char *res, char *current, int *rv, const int fd);

#endif
