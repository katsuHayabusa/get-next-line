/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:12:34 by saichaou          #+#    #+#             */
/*   Updated: 2023/03/16 15:51:48 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_stash(int fd, char *stash)
{
	char	*buf;
	int		status;

	if (fd < 0)
		return (NULL);
	status = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (status && !ft_strchr(stash, '\n'))
	{
		status = read(fd, buf, BUFFER_SIZE);
		if (status == -1)
			return (free(buf), NULL);
		if (status == 0)
			return (free(buf), stash);
		buf[status] = '\0';
		stash = strjoin(stash, buf);
		ft_bzero(buf, BUFFER_SIZE);
	}
	return (free(buf), stash);
}

char	*trim_stash(char *stash)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (i == ft_strlen(stash))
		return (NULL);
	res = malloc(ft_strlen(stash) - i + 2);
	if (!res)
		return (NULL);
	while (stash[i + j])
	{
		res[j] = stash[i + j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*get_line(char *stash)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	res = malloc((i + 2) * sizeof(char));
	if (!res)
		return (NULL);
	while (j <= i)
	{
		res[j] = stash[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char			*stash;
	char			*line;
	static char		*trimmed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = trimmed;
	stash = get_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	trimmed = trim_stash(stash);
	if (!line)
		return (free(stash), NULL);
	free(stash);
	return (line);
	
}

int main(void)
{
	int		fd;
	int		fd2;

	fd = open("mam", O_RDONLY);
	fd2 = open("dad", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd2);
	printf("%s", str);
	free(str);
}
