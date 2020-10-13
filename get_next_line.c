/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:36:28 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/28 12:23:41 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_strdel(char **s)
{
	if (s == 0)
		return ;
	if (*s)
		free(*s);
	*s = 0;
}

static int		ft_line(char **str, char **line)
{
	char	*aux;
	size_t	i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
	{
		*line = ft_substr(*str, i);
		aux = ft_strdup(&((*str)[i + 1]));
		free(*str);
		*str = aux;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
		return (0);
	}
	return (1);
}

static int		ft_return(char **str, char **line, int n, int fd)
{
	if (n < 0)
		return (-1);
	else if (n == 0 && str[fd] == NULL)
	{
		*line = ft_calloc((sizeof(char)), 1);
		return (0);
	}
	return (ft_line(&str[fd], line));
}

int				get_next_line(int fd, char **line)
{
	static char	*perm[OPEN_MAX];
	char		*bff;
	char		*temp;
	int			n;

	if (!(bff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	if (fd < 0 || line == 0 || BUFFER_SIZE < 1)
		return (-1);
	while ((n = read(fd, bff, BUFFER_SIZE)) > 0)
	{
		bff[n] = '\0';
		if (perm[fd] == NULL)
			perm[fd] = ft_strdup(bff);
		else
		{
			temp = ft_strjoin(perm[fd], bff);
			free(perm[fd]);
			perm[fd] = temp;
		}
		if (ft_strchr(perm[fd], '\n'))
			break ;
	}
	ft_strdel(&bff);
	return (ft_return(perm, line, n, fd));
}
