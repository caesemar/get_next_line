/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:10:26 by jocasado          #+#    #+#             */
/*   Updated: 2023/01/18 15:11:18 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (read(fd, 0, 0) < 0)
	{
		if (buffer[fd] != NULL)
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer [fd] = read_file(buffer[fd], fd);
	if (buffer[fd] == 0)
	{
		free(buffer[fd]);
		return (0);
	}
	line = gt_line(buffer[fd]);
	buffer[fd] = new_buffer(buffer[fd]);
	return (line);
}

char	*read_file(char *buffer, int fd)
{
	int		j;
	char	*buff;

	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	j = 1;
	while (j > 0)
	{
		j = read(fd, buff, BUFFER_SIZE);
		if (j < 0)
		{
			free (buff);
			return (0);
		}
		buff[j] = 0;
		buffer = join_free(buffer, buff);
		if (find_nl(buff) == 1)
			break ;
	}
	free (buff);
	return (buffer);
}

char	*join_free(char *buffer, char *buff)
{
	char	*temp;

	temp = ft_strjoin(buffer, buff);
	free (buffer);
	return (temp);
}

char	*new_buffer(char *buff)
{
	char	*n_buffer;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (buff[i] == 0)
	{	
		free (buff);
		return (0);
	}
	while (buff[i] && buff[i] != '\n')
		i++;
	n_buffer = ft_calloc(ft_strlen(buff) - i + 1, sizeof(char));
	while (buff[i++])
		n_buffer[j++] = buff[i];
	free (buff);
	return (n_buffer);
}

char	*gt_line(const char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (0);
	while (buff[i] && buff[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n' && buff[i])
		line[i] = '\n';
	return (line);
}
