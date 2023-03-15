/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saichaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:37:32 by saichaou          #+#    #+#             */
/*   Updated: 2023/03/15 14:24:12 by saichaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
# define BUFFER_SIZE	5
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*strjoin(char *s1, char *s2);
void	ft_bzero(void *mem, size_t size);
int		ft_strlen(char *str);
char	*get_line(char *str);
char	*trim_stash(char *stash);
#endif
