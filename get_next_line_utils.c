/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:27 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/07 10:58:56 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char					*new_string;
	unsigned int			len;
	unsigned int			i;
	unsigned int						counter;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = strlen(s1) + strlen(s2);
	new_string = (char *)malloc(len + 1);
	counter = 0;
	i = 0;
	if (!new_string)
		return (NULL);
	while (i < strlen(s1))
	{
		new_string[i] = s1[i];
		i++;
	}
	while (counter <= strlen(s2))
	{
		new_string[i] = s2[counter];
		i++;
		counter++;
	}
	return (new_string);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size > 0 && (SIZE_MAX / size) < count)
		return (NULL);
	p = malloc (count * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
