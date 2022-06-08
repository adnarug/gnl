/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/08 18:18:42 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./get_next_line.h"
#include	<stdio.h>

char	*get_next_line(int fd)
{
	char		*read_line;
	char		*temp;
	int			*buff_counter;
	char		*next_line;
	char		*rest_point;
	static char	*rest;

	//static char	*rest;
	//rest = NULL;
	buff_counter = malloc(sizeof(int));
		temp = NULL;
	if(buff_counter == NULL)
		return (NULL);
	*buff_counter = 1;
	//First iteration - fills with buff and gives a string which is + buf in size
	if (rest == NULL)
		read_line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	else
	{
		read_line = malloc(sizeof(char) * BUFFER_SIZE + 1 + sizeof(rest));
		strcpy(read_line, rest);
		read_line += strlen(rest);
	}
	if (rest == NULL)
	{
		get_line(buff_counter, fd, BUFFER_SIZE, &read_line);
		memory_line(BUFFER_SIZE, read_line, &temp);
		free(read_line);
		read_line = NULL;
	}
	if (rest != NULL)
	while(strchr(read_line,'\n') == NULL)
	{
		{
			read_line = malloc(sizeof(temp));
			strcpy(read_line, (const char*)temp);
			//printf("read_line: %s \n", read_line);
			free(temp);
			temp = NULL;
			get_line(buff_counter, fd, BUFFER_SIZE, &read_line);
			memory_line(BUFFER_SIZE, read_line, &temp); //+1?
		}
	//Second and following iterations - re-assigning to read_line, empty temp and fill it with the new values
	if (rest == NULL)
	while(strchr(temp,'\n') == NULL)
	{
		{
			read_line = malloc(sizeof(temp));
			strcpy(read_line, (const char*)temp);
			//printf("read_line: %s \n", read_line);
			free(temp);
			temp = NULL;
			get_line(buff_counter, fd, BUFFER_SIZE, &read_line);
			memory_line(BUFFER_SIZE, read_line, &temp); //+1?
		}
	}
	read_line[strlen(read_line)] = '\0';
	printf("before split: %s \n", read_line);
	//If there is \n sign then I need to put it away
	rest_point = strchr(read_line, '\n');
	if(rest_point != NULL && *(rest_point + 1) != '\0')
	splitting(read_line, rest_point, &rest);
	printf("before split: %s \n", read_line);
	return (read_line);
}

void	get_line(int *iter, int fd, int buf, char **next_line)
{
	char *end;
	if (*iter == 1)
	{
		read(fd, *next_line, buf);
		// printf ("first ");
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
}

void	splitting(char *next_line, char *rest_point, char **rest)
{
	int	i;
	int z;

	i = 0;
	z = 0;
	while (next_line <= rest_point)
	{
		next_line++;
		i++;
	}	
	z = strlen(next_line);
	*rest = malloc(sizeof(strlen(next_line)));
	if (*rest == NULL)
		return ;
	while (*next_line != '\0')
	{
		**rest = *next_line;
		*next_line = '\0';
		next_line++;
		*rest += 1;
		i++;
	}
	*rest -= z;
	next_line -= i;
}