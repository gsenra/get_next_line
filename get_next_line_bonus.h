/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:37:02 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/28 12:39:39 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
