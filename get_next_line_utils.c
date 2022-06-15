/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasha <pasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:27 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/15 23:08:08 by pasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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
		unsorted_line =  malloc(1 * sizeof(char));
		*unsorted_line = '\0';
	}
	if (unsorted_line == NULL)
		return (NULL);
	len = strlen(new_line) + strlen(unsorted_line);
	new_string = malloc(sizeof(char) * (len) + 1);//+1
	if (new_string == NULL)
		return NULL;
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
	new_string[len] = '\0';
	free(unsorted_line);
	unsorted_line = NULL;
	return(new_string);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i + 1);
	return (NULL);
}

// void struct_default_values(t_arg **line)
// {
// 	line->read_line = NULL;
// 	line->temp = NULL;
// 	*line->buf_counter = 0;
// 	line->next_line = NULL;
// 	line->unsorted_line = NULL;
// }