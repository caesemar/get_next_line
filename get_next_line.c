/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:10:26 by jocasado          #+#    #+#             */
/*   Updated: 2022/10/15 23:53:17 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


// to do : bufftrim

char	*get_next_line(int fd)
{
	static char	*buff; // para hacer el bonus tiene que ser una estructura, 2 variables dentro, static buff y fd(o 4, con line y i). Tambien tiene que enlazar a otra lista, si en la siguiente llamada el fd no es el mismo, primero recorre hacia detras para ver si ya existe, si no, crea uno nuevo con el nuevo buffer y el fd.
	char		*line;
	int			*i;
	int			*j;

	*i = 0;
	*j = 0;
	if (buff == 0) //caso en el que no hay buffer
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // o (...,sizeof(char) * (buffer_size))
		*i = read (fd, buff, BUFFER_SIZE);		//nullterminar buff?
		if (*i < 0)
		{	
			free (buff);
			return (0);
		}
		*i = 0;
		endl_found(line, &i);
		line = ft_strdup(buff, *i);
	}
	else if (endl_found(buff, &i) == 1) //caso en el que el buffer ya creado tiene un /n
	{
		line = ft_strdup(buff, *i);
		buff = bufftrim(buff, *i); // funcion que recorta line de buff, y null termina el sobrante por la derecha
	}
	else //caso en el que hay buffer, pero no tiene /n
	{
		line = ft_strdup(buff, ft_strlen(buff));
		*i = read (fd, buff, BUFFER_SIZE); // estos *i no son correctos, otra variable (en este caso, i esta en el /0 del buffer)
		if (*i < 0)
		{	
			free (buff);
			return (0);
		}
		*i = 0;
		buff = ft_strjoin(line, buff); //este buff contiene lo que queda del buffer antiguo y el nuevo, !cuidado porque no hemos liberado line antes de hacer otro malloc para meter en el nuevo line todo!, si falla crear nueva variable char *
		if (endl_found(buff, &i) == 0) //pone en j la posicion donde se encuentra el nl en buff;
			return (0);
		line = ft_strdup(line, *i);
		buff = bufftrim(buff, j); //pongo j porque no es i, que en este caso es el indice de line // retorna un nuevo char * del principio de line hasta \n;
	}
	return (line);
}
