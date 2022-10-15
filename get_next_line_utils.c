/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:20:45 by jocasado          #+#    #+#             */
/*   Updated: 2022/10/15 23:52:57 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	endl_found(const char *buff, int *i)
{
	while (buff[*i] != 0)
	{	
		if (buff[*i] == '\n')
			return (1);
		*i = *i + 1;
	}
	return (0);
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

char	*ft_strdup(const char *s1, int j)
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

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
