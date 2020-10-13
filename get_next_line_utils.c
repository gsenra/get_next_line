/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:41:55 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/28 12:33:00 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t			*c;
	size_t			i;
	unsigned char	*swp;

	i = num;
	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	if (!(c = malloc(num * size)))
		return (0);
	swp = (unsigned char*)c;
	while (i > 0)
	{
		*(swp++) = '\0';
		i--;
	}
	return (c);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (!(dup = ft_calloc((i + 1), (sizeof(char*)))))
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *first, char *second)
{
	int		i;
	int		c;
	char	*ans;

	i = 0;
	while (first[i] != '\0')
		i++;
	c = 0;
	while (second[c] != '\0')
		c++;
	if (!(ans = ft_calloc((i + c + 1), (sizeof(char*)))))
		return (0);
	i = 0;
	while (first[i] != '\0')
	{
		ans[i] = first[i];
		i++;
	}
	c = 0;
	while (second[c] != '\0')
	{
		ans[i + c] = second[c];
		c++;
	}
	return (ans);
}

char	*ft_strchr(char *str, char cc)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == cc)
			return ((char*)&str[i]);
		i++;
	}
	if (cc == '\0')
		return ((char*)&str[i]);
	return (0);
}

char	*ft_substr(char *str, int i)
{
	int		c;
	char	*ans;

	if (str == NULL)
		return (0);
	c = 0;
	while (str[c] != '\0')
		c++;
	if (c < i)
		return (ft_strdup(""));
	ans = ft_calloc((i + 1), (sizeof(char)));
	if (ans == NULL)
		return (0);
	c = 0;
	while (c < i)
	{
		ans[c] = str[c];
		c++;
	}
	return (ans);
}
