/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:27 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/09 18:22:46 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_merge(char  *new_line, char  **rest)
{
	char					*new_string;
	unsigned int			len;
	unsigned int			i;
	unsigned int			counter;

	new_string = malloc(sizeof(char) * strlen(new_line) + sizeof(char) * strlen(*rest) + 1);
	if (new_line == NULL || rest == NULL || new_string == NULL)
		return (NULL);
	len = strlen(new_line) + strlen(*rest);
	counter = 0;
	i = 0;
	while (i < strlen(*rest))
	{
		new_string[i] = *rest[i];
		i++;
	}
	while (counter <= strlen(new_line))
	{
		new_string[i] = new_line[counter];
		i++;
		counter++;
	}
	free(new_line);
	new_line = NULL;
	free(rest);
	rest = NULL;
	return (new_string);
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
// 	line->rest = NULL;
// }