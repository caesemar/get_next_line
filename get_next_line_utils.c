/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:20:45 by jocasado          #+#    #+#             */
/*   Updated: 2022/11/02 15:31:24 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*str;
	size_t		len;

	len = count * size;
	if (len && (len / size != count))
		return (0);
	str = (char *) malloc(size * count);
	if (!str)
		return (0);
	ft_bzero(str, len);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	start;
	size_t	i;

	i = 0;
	start = 0;
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (start < ft_strlen(s1))
	{
		str[start] = s1[start];
		start++;
	}
	while (i < ft_strlen(s2))
	{
		str[start] = s2[i];
		start++;
		i++;
	}
	str[start] = 0;
	return (str);
}

char	*ft_strdup(const char *s1, size_t j)
{
	char		*s2;
	size_t		i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (j + 1));
	if (!s2)
		return (0);
	while (i < j)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*bufftrim(char *buff, int i)
{
	int	j;

	j = 0;
	while (buff[i] != 0)
	{
		buff[j++] = buff[i];
		i = i + 1;
	}
	while (buff[j] != 0)
		buff [j++] = 0;
	return (buff);
}
