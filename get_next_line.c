/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/02 15:49:13 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./get_next_line.h"
#include	<stdio.h>
#include	<string.h>

/*char	*get_next_line(int fd)
{
	// int		len;
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
}*/

int	check_line(char *temp, int buf)
{
	int		i;
	char	*s;
	int		buf_temp;
	char	*new_line;
	char	*end;
	
	i = 0;
	s = NULL;
	new_line = NULL;
	end = NULL;
	buf_temp = buf;

	if (strchr(temp, '\n') != NULL || strchr(temp, '\0') != NULL)// TODO: write my own strrchr
	{
		new_line = strchr(temp, '\n');
		end = strchr(temp, '\0');
		if (*temp == '\0')
			return (0);
		while (temp < new_line || temp < end)
		{
			write (1, &(*temp), 1);
			temp++; 
		}
		if (*temp == '\n')
		{
			write (1, "\n", 1);
			temp++;
		}
	check_line(temp, buf);
	}
	return (0);
}

int main ()
{
	char s[30] = "Hello \nmy friend \nagain";
	check_line(s, 2);
	return (1);
}

	/*while (temp[i] != '\n' && temp[i] != '\0' && temp[i] != 'Z')
	{
		write (1, &temp[i], 1);
		i++;
	}
	if (temp[i] == '\n' && buf > i)
	{
		write(1, "\n", 1);
		s = malloc(sizeof(char)*(buf - i));
		*s = temp[i];
		i++;
		s++;
	}
	if (temp[i] == 'Z')
	{
		// write (1, "!", 1);
		return (0);
	}*/