/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/03 16:02:28 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./get_next_line.h"
#include	<stdio.h>
#include	<string.h>


char	*get_next_line(int fd)
{
	// int		len;
	char	*next_line;
	char	*new_line;
	int		*i;

	next_line = NULL;
	new_line = NULL;
	printf ("check");
	i = malloc(sizeof(int));
	*i = 1;
	next_line = malloc(sizeof(char) * BUFFER_SIZE + 1) + strlen(next_line);// what is the correct malloc size? how do i know how big will be the next line?
	if(next_line == NULL)
		return (NULL);
	new_line = malloc(sizeof(char)* (*i) * BUFFER_SIZE);
	new_line = check_line(i, fd, BUFFER_SIZE, next_line);
	return (new_line);
}

char*	check_line(int *iter, int fd, int buf, char *next_line)
{
	char	*temp;

	temp = malloc(sizeof(char) * buf + 1);
	read(fd, temp, buf);
	// next_line[buf] = '\0';
	while (strchr(temp, '\n') == NULL && strchr(temp, '\0') == NULL) //maybe check if the line exists
	{
		read(fd, next_line, buf);
		temp = ft_strjoin((const char*)temp, (const char*)next_line);
		*iter += 1;
	}
	printf (" here: %s ", temp);
	return (temp);
}


	/*if (strchr(temp, '\n') != NULL || strchr(temp, '\0') != NULL)// TODO: write my own strrchr
	{
		new_line = strchr(temp, '\n');
		end = strchr(temp, '\0');
		if (*temp == '\0')
			return NULL;
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
	// check_line(temp, buf);
	}
	return (temp);
}*/

// int main ()
// {
// 	open ("")
// 	get_next_line(s);
// 	return (1);
// }

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