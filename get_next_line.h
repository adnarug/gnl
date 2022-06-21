/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:31 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/21 11:29:09 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#endif

char	*split_next_line(char *unsorted_line);
char	*split_remainder(char *unsorted_line);
char	*read_until_nl(int fd, char *unsorted_line);
char	*get_next_line(int fd);
char	*line_merge(char  *new_line, char  *unsorted_line);
int	    ft_strchr(const char *s, int c);
void	gn_free_buf(char **buf);
void	ft_free(void *pointer);
char	*gn_set_buf(char *buf);
int		ft_strcpy(char *dst, const char *src, size_t start);
int		ft_strlen(const char *c);

#endif