/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasha <pasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:31 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/07 22:41:38 by pasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_H
#define		GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
	
char	*get_next_line(int fd);
void	get_line(int *iter, int fd, int buf, char **next_line);
char	*ft_strjoin(char const *s1, char const *s2);
void	memory_line(int buffer_size, char *read_line, char **temp);
void	*ft_calloc(size_t count, size_t size);

#endif