/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:27 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/20 20:12:13 by pguranda         ###   ########.fr       */
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
	{
		unsorted_line = malloc(sizeof(char) * 1);
		if (unsorted_line != NULL)
			return (NULL);
			*unsorted_line = '\0';
		}
	len = strlen(new_line) + strlen(unsorted_line);
	new_string = malloc(sizeof(char) * (len) + 1);//+1
	if (new_string == NULL)
		return (NULL);
	ft_strcpy(new_string, unsorted_line, &i, &i);
	ft_strcpy(new_string, new_line, &i, &counter);
	gn_free_buf(&unsorted_line);
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

int	ft_strlen(const char *c)
{
	size_t				i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

void	ft_strcpy(char *dst, const char *src, unsigned int *dst_start, unsigned int *src_start)
{
	unsigned int				counter;
	int							flag;

	counter = 0;
	if (*dst_start == 0 && *src_start == 0)
		flag = 1;
	while (src[*src_start] != '\0')
	{
		dst[*dst_start] = src[*src_start];
		*dst_start += 1;
		*src_start += 1;
	}
	if (flag != 1)
		dst[*dst_start] = '\0';
	return ;
}
