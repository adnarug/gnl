/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/01 13:48:39 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./get_next_line.h"
#include	<stdio.h>

char	*get_next_line(int fd)
{
	int		len;
	void	*temp;
	int		i;

	temp = NULL;
	i = 1;

	while (i == 1)
	{
		temp = malloc(sizeof(BUFFER_SIZE) + 1);
		if (temp == NULL)
			return (NULL);
		read(fd, temp, BUFFER_SIZE);
		i = check_line((char *)temp, BUFFER_SIZE);
		free(temp);
		temp = NULL;
	}
	return (temp);
}

int	check_line(char *temp, int buf)
{
	int		i;
	char	*s;
	int		buf_temp;
	
	i = 0;
	s = NULL;
	buf_temp = buf;
	while (temp[i] != '\n' && temp[i] != '\0' && buf_temp > i)
	{
		write (1, &temp[i], 1);
		i++;
		buf_temp--;
	}
	write (1, "\n", 1);
	if (temp[i] == 'k' && buf > i)
	{
		s = malloc(sizeof(char)*(buf - i));
		*s = temp[i];
		i++;
		s++;
	}
	if (temp[i] == '\0')
		return (0);
	return (1);
}
