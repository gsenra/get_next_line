/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:45:16 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/28 12:39:49 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		get_next_line(int fd, char **line);

void	*ft_calloc(size_t tipo, size_t size);

char	*ft_strdup(char *str);

char	*ft_strjoin(char *first, char *second);

char	*ft_strchr(char *str, char cc);

char	*ft_substr(char *str, int i);

#endif
