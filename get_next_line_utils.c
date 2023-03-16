/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:17:17 by saichaou          #+#    #+#             */
/*   Updated: 2023/03/16 15:27:49 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *mem, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *) mem)[i] = '\0';
		i++;
	}
}

char	*strjoin(char *stash, char *buf)
{
	char	*res;
	int		i;
	int		j;

	if (!buf)
		return (stash);
	i = 0;
	j = -1;
	res = malloc((ft_strlen(stash) + ft_strlen(buf) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (stash)
	{
		while (stash[i])
		{
			res[i] = stash[i];
			i++;
		}
		free(stash);
	}
	while (buf[++j])
		res[i + j] = buf[j];
	res[i + j] = '\0';
	return (res);
}
