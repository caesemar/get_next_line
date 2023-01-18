/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:20:45 by jocasado          #+#    #+#             */
/*   Updated: 2023/01/18 14:58:14 by jocasado         ###   ########.fr       */
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
	size_t	len1;
	size_t	len2;

	i = 0;
	start = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (0);
	while (start < len1)
	{
		str[start] = s1[start];
		start++;
	}
	while (i < len2)
		str[start++] = s2[i++];
	str[start] = 0;
	return (str);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != 0)
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	size_t			i;

	i = 0;
	a = (unsigned char *) s;
	if (n != 0)
	{
		while (i < n)
		{
			a[i] = 0;
			i++;
		}
	}
}

int	find_nl(const char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != 0)
	{	
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
