/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:31 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/15 11:36:52 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
// char	*get_next_line(int fd);
// void	get_line(int *iter, int fd, int buf, char **next_line);
// char	*ft_strjoin(char const *s1, char const *s2);
// void	memory_line(int buffer_size, char *read_line, char **temp);
// void	*ft_calloc(size_t count, size_t size);
// void	splitting(char *next_line, char *unsorted_line_point, char **unsorted_line);
// void	ft_bzero(void *s, size_t n);
// // void	struct_default_values(t_arg **line);

char	*split_next_line(char *unsorted_line, int *last_read);
char	*split_remainder(char *unsorted_line);
void	read_until_nl(int fd, char **unsorted_line, int *last_read);
char	*get_next_line(int fd);
char	*line_merge(char  *new_line, char  *unsorted_line);
char	*ft_strchr(const char *s, int c);
void	ft_free(void *pointer);


#endif