/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/07 16:32:07 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./get_next_line.h"
#include	<stdio.h>

char	*get_next_line(int fd)
{
	char		*read_line;
	char		**temp;
	int			*buff_counter;
	static char	*rest;

	rest = NULL;
	buff_counter = malloc(sizeof(int));
	read_line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	temp = NULL;
	if(buff_counter == NULL)
		return (NULL);
	*buff_counter = 1;
	if(*buff_counter == 1)//first iteration, setting memory, filling with buff, copying it to buff with more space 
	{	
		read_line = malloc(sizeof(char) * BUFFER_SIZE + 1);
		get_line(buff_counter, fd, BUFFER_SIZE, read_line);		
		memory_line(BUFFER_SIZE, read_line, temp);
	}
	printf ("temp after cpy: %s \n temp len after cpy: %lu \n", &temp, strlen(&temp));

	// while (strchr(read_line, '\n') == NULL)
	// {
	// 	read_line = malloc(sizeof(temp));
	// 	printf("Hi");
	// 	strcpy(read_line, (const char*)temp);
	// 	// // free(temp);
	// 	// // temp = NULL;
	// 	// get_line(buff_counter, fd, BUFFER_SIZE, read_line);
	// 	// memory_line(buff_counter, BUFFER_SIZE, read_line, temp); //+1?
	// }
	// if (strchr(read_line, '\n') != NULL)
	// {
	// 	rest = strchr(read_line, '\n');
	// 	free(rest);
	// 	rest = NULL;
	// }
	//free(buff_counter);
	return (read_line);
}

void		get_line(int *iter, int fd, int buf, char *next_line)
{
	if (*iter == 1)
		read(fd, next_line, buf);
	// else
	// read(fd, next_line + (buf * (*iter)), buf); 
	next_line[strlen(next_line)] = '\0';
	// printf ("tracing: %d",	next_line[strlen(next_line)]);
	*iter += 1;	// temp = malloc(sizeof(char) * buf + 1);
}

void	memory_line(int buffer_size, char *read_line, char **temp)
{
	int		i;

	printf ("entering memline: %s \n", read_line);
	temp = malloc(sizeof(read_line) + buffer_size);
	i = 0;
	while (read_line[i] != '\0')
	{
		*temp[i] = read_line[i];
		i++;
	}
	printf ("temp after cpy: %s \n temp len after cpy: %lu \n", *temp, strlen(*temp));
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
	/		get_line(temp, buf);
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