/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/10 12:44:38 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./get_next_line.h"
#include	<stdio.h>
#include 	<fcntl.h>


char	*get_next_line(int fd)
{

	int			*buff_counter;
	char		*next_line;
	static char	*rest;

	//static char	*rest;
	//rest = NULL;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff_counter = malloc(sizeof(int));
	//rest = malloc(BUFFER_SIZE + 1);
	if(buff_counter == NULL)
		return (NULL);
	*buff_counter = 1;
	rest = get_line(fd, rest, buff_counter);
	next_line = split_next_line(rest);
	rest = split_remainder(&rest);
	return (next_line);
}

char *split_next_line(char *rest)
{
	char	*new_line;
	char	*line_break_point;
	int		i;

	i = 0;
	while (rest[i] != '\n')
		i++;
	i = 0;
	new_line = malloc(sizeof(char)* i + 2);
	line_break_point = strchr(rest, '\n');
	while(line_break_point != NULL && &rest[i] <= line_break_point)
	{
		new_line[i] = rest[i]; // maybe both i and pointer increase will not work 
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char *split_remainder(char **rest)
{
	unsigned int		i; 
	char	*remainder;
	int d;


	i = 0;
	d = 0;
	while (**rest != '\n')
		*rest += 1;
	*rest += 1;
	i = strlen(*rest);
	if (i == 0)
		return (NULL);
	remainder = malloc(sizeof(char) * i + 3);
	if (remainder == NULL)
		return (NULL);
	strcpy(remainder, *rest);
	remainder[i] = '\0';
	*rest = NULL;
	return(remainder);
}

char	*get_line(int fd, char *rest, int *buf_counter)
{
	char	*new_line;
	int		read_result;

	read_result = 1;
	new_line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(new_line == NULL)
		return (NULL);
	while (ft_strchr(rest, '\n') == NULL && read_result != 0)
	{
		read_result = read(fd, new_line, BUFFER_SIZE);
		if(read_result == -1)
		{
			free(new_line);
			new_line = NULL;
			return (NULL);
		}
		*buf_counter += 1;
		new_line[*buf_counter * BUFFER_SIZE + 1] = '\0';
		rest = line_merge(new_line, rest);
	}
	free(new_line);
	new_line = NULL;
	return (rest);
}

int	main(void)
{
	char	*s;
	int fd;
	fd = 0;
	fd = open("/Users/pguranda/Projects/gnl_wip/text", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	free(s);
	//s = NULL;
	// printf("%s", get_next_line(fd));
	//printf("%s", ft_strjoin("\n\n", buffer));
	return (0);
}