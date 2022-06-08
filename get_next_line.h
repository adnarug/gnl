/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:31 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/08 13:11:46 by pguranda         ###   ########.fr       */
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
void	splitting(char *next_line, char *rest_point, char **rest);
void	ft_bzero(void *s, size_t n);
// void	struct_default_values(t_arg **line);

#endif