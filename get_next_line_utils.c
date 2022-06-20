/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:27 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/20 19:07:25 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"


char	*line_merge(char  *new_line, char  *unsorted_line)
{
	char					*new_string;
	unsigned int			len;
	unsigned int			i;
	unsigned int			counter;

	i = 0;
	counter = 0;
	if (unsorted_line == NULL)
		unsorted_line = gn_set_buf(unsorted_line);
	len = strlen(new_line) + strlen(unsorted_line);
	//printf ("length: %lu \n", strlen(new_line));
	new_string = malloc(sizeof(char) * (len) + 1);//+1
	if (new_string == NULL)
		return (NULL);
	while (unsorted_line[i] != '\0')
	{
		new_string[i] = unsorted_line[i];
		i++;
	}
	while (new_line[counter] != '\0')
	{
		new_string[i] = new_line[counter];
		i++;
		counter++;
	}
	new_string[i] = '\0';
	gn_free_buf(&unsorted_line);
	//printf ("**** from the merge: *** \n new_line(tmp): %s new_string(join): %s unsorted: %s\n", new_line, new_string, unsorted_line);
	return(new_string);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return (1);
	return (0);
}

void	gn_free_buf(char **buf)
{
	free(*buf);
	*buf = NULL;
}

char	*gn_set_buf(char *buf)
{
	buf = malloc(sizeof(char) * 1);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	return (buf);
}

int	ft_strlen(const char *c)
{
	size_t				i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_strcpy(char *dst, const char *src, size_t start)
{
	unsigned int				counter;

	counter = 0;
	while (src[start] != '\0')
	{
		dst[counter] = src[start];
		start++;
		counter++;
	}
	dst[counter] = '\0';
	return ;
}
