/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:10:26 by jocasado          #+#    #+#             */
/*   Updated: 2022/11/02 15:56:31 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*temp;
	char		*line;
	size_t		i;
	int			j;

	i = 0;
	j = 1;
	if (read(fd, 0, 0) < 0)
		return (0);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff[fd])
	{
		buff[fd] = buff_create(fd);
		if (!buff[fd])
			return (0);
	}
	while (j > 0)
	{
		line = ft_strdup(buff[fd], ft_strlen(buff[fd]));
		j = read(fd, temp, BUFFER_SIZE);
		if (j == -1)
		{
			free(temp);
			free (line);
			return (0);
		}
		if (buff[fd])
			free (buff[fd]);
		buff[fd] = ft_strjoin(temp, line);
		free (line);
		if (endl_found(buff[fd], &i) == 1)
			break ;
	}
	free (temp);
	if (endl_found(buff[fd], &i) == 1)
		return (endl_on_buff(buff[fd], i));
	return (buff[fd]);
}

char	*endl_on_buff(char *buff, int i)
{
	char	*line;

	//printf("%d\n", i); //quitar
	line = ft_strdup(buff, i);
	//printf("antes :%s\n", buff);
	buff = bufftrim(buff, i);
	//printf("despues:%s\n", buff);
	if (buff[0] == 0)
		free (buff);
	return (line);
}

char	*buff_create(int fd)
{
	int		j;
	char	*buff;

	buff = ft_calloc(BUFFER_SIZE +1, sizeof(char));
	if (!buff)
		return (0);
	j = read(fd, buff, BUFFER_SIZE);
	if (j == -1)
	{
		free(buff);
		return (0);
	}
	buff[j] = 0;
	return (buff);
}

int	endl_found(const char *buff, size_t *i)
{
	*i = 0;
	while (buff[*i] != 0)
	{	
		if (buff[*i] == '\n')
		{	
			*i = *i + 1;
			return (1);
		}
		*i = *i + 1;
	}
	return (0);
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

/*
	else if (endl_found(buff[fd], &i) == 1)
	{
		line = ft_strdup(buff[fd], i);
		buff[fd] = bufftrim(buff[fd], i);
	}




	else
	{
		line = ft_strdup(buff[fd], ft_strlen(buff[fd]));
		free (buff[fd]);
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0)
		{
			free(buff[fd]);
			free(temp);
			return (0);
		}
		temp[i] = 0;
		i = 0;
		buff[fd] = ft_strjoin(line, temp);
		free(temp);
		free(line);
		if (endl_found(buff[fd], &i) == 0)
			return (0);
		line = ft_strdup(buff[fd], i);
		buff[fd] = bufftrim(buff[fd], i);
	}
	return (line);
}
*/