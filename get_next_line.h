/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:17:53 by jocasado          #+#    #+#             */
/*   Updated: 2023/01/18 14:58:15 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 60
# endif

char	*get_next_line(int fd);
char	*gt_line(const char *buff);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *c);
char	*new_buffer(char *buff);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*read_file(char *buffer, int fd);
char	*join_free(char *buffer, char *buff);
int		find_nl(const char *buff);
#endif