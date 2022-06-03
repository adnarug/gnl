/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:31 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/03 12:41:53 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_H
#define		GET_NEXT_LINE_H
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
	
char	*get_next_line(int fd);
char*	check_line(int *iter, int fd, int buf, char *next_line);
char	*ft_strjoin(char const *s1, char const *s2);

#endif