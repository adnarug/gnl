/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_join.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/08 12:15:59 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./get_next_line.h"
#include	<stdio.h>

char	*get_next_line(int fd)
{
	char		*read_line;
	char		*temp;
	int			*buff_counter;
	
	//static char	*rest;
	//rest = NULL;
	buff_counter = malloc(sizeof(int));
	temp = NULL;
	if(buff_counter == NULL)
		return (NULL);
	*buff_counter = 1;
	read_line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	get_line(buff_counter, fd, BUFFER_SIZE, &read_line);
	memory_line(BUFFER_SIZE, read_line, &temp);
	free(read_line);
	read_line = NULL;
	while(strchr(temp,'\n') == NULL)
	{
	 	read_line = malloc(sizeof(temp));
		strcpy(read_line, (const char*)temp);
		printf("read_line: %s \n", read_line);
		free(temp);
		temp = NULL;
		get_line(buff_counter, fd, BUFFER_SIZE, &read_line);
		memory_line(BUFFER_SIZE, read_line, &temp); //+1?
	}
	if(strchr(read_line, '\n') != NULL)
	{
		rest_point = strchr(read_line, '\n');
		splitting(read_line, &rest_point, rest)
	}
	free(buff_counter);
	return (read_line);
}

void		get_line(int *iter, int fd, int buf, char **next_line)
{
	char *end;
	if (*iter == 1)
	{
		read(fd, *next_line, buf);
		printf ("first ");
		*iter += 1;
		return ;
	}
	end = *next_line + strlen(*next_line);
	read(fd, end , buf); 
	// *next_line[strlen(*next_line)] = '\0';
	// printf ("tracing: %d",	next_line[strlen(next_line)]);
		// temp = malloc(sizeof(char) * buf + 1);
}

void	memory_line(int buffer_size, char *read_line, char **temp)
{

	*temp = malloc(sizeof(read_line) + buffer_size);
	strcpy(*temp, (const char *)read_line);
	// printf ("MEMORY_LINE FT: temp after cpy: %s  temp len after cpy: %lu \n", *temp, strlen(*temp));
}

void splitting(char *next_line, char *rest_point, char **rest)
{
	while (next_line <= rest_point)
		next_line++;
	*rest = malloc(strlen(next_line));
	while (*next_line != '\0')
	{
		*rest = *next_line;
		next_line++;
		rest++;
	}
}