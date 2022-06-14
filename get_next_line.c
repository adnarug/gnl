/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/14 17:19:09 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./get_next_line.h"
#include	<stdio.h>
#include 	<fcntl.h>


char	*get_next_line(int fd)
{
	static char	*rest;
	char		*next_line;
	int			last_read;

	last_read = 0;
	next_line = NULL;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_until_nl(fd, &rest, &last_read);
	next_line = split_next_line(rest, &last_read);
	rest = split_remainder(rest);
	return (next_line);
}

void	read_until_nl(int fd, char **rest, int *last_read)
{
	char	*new_line;
	int		read_result;
	int		buf_iterations;

	read_result = 1;
	buf_iterations = 1;
	new_line = NULL;
	new_line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(new_line == NULL)
		return ;
	while ((ft_strchr(*rest, '\n') == NULL) && read_result > 0)
	{
		read_result = read(fd, new_line, BUFFER_SIZE);
		if(read_result == -1)
		{
			free(new_line);
			new_line = NULL;
			return ; // maybe break and save some lines?
		}
		if(read_result == 0)
		{
			*last_read = 1;
			*rest = line_merge(new_line, *rest);
			break;
		}
		buf_iterations++;
		new_line[buf_iterations * BUFFER_SIZE] = '\0';
		*rest = line_merge(new_line, *rest);
		bzero(new_line, BUFFER_SIZE);
	}
	free(new_line);
	new_line = NULL;
}

char *split_next_line(char *rest, int *last_read)
{
	char	*new_line;
	int		i;

	i = 0;
	while (strchr(rest, '\n') != NULL && rest[i] != '\n')// zero here?
		i++;
	new_line = malloc(sizeof(char) * i + 2);
	i = 0;
	while(((strchr(rest, '\n') != NULL) || (strchr(rest, '\0') != NULL)) && ((rest[i] != '\n') && (rest[i] != '\0')))
	{
		new_line[i] = rest[i]; 
		i++;
	}
	if (*last_read == 0)
	{
		new_line[i] = '\n';
		new_line[i + 1] = '\0';
	}
	return (new_line);
}

char *split_remainder(char *rest)
{
	unsigned int		i; 
	unsigned int		d;
	char				*remainder;

	i = 0;
	d = 0;
	while (rest[i] != '\n' && rest[i] != '\0')
		i++;
	if (rest[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	remainder = malloc(sizeof(char) * i);
	if (remainder == NULL)
		return (NULL);
	strcpy(remainder, &rest[i]);
	free(rest);
	rest = NULL;
	return(remainder);
}


int	main(void)
{
	char	*s;
	int fd;
	fd = 0;
	int i;

	i = 1;
	fd = open("/Users/pguranda/Projects/gnl_wip/text", O_RDONLY);
	s = NULL;
	s = get_next_line(fd);
	printf ("%s", s);
	s = get_next_line(fd);
	printf ("%s", s);
	s = get_next_line(fd);
	printf ("%s", s);
	s = get_next_line(fd);
	printf ("%s", s);
	s = get_next_line(fd);
	printf ("%s", s);
	s = get_next_line(fd);
	printf ("%s", s);
	// while (i <= 7)
	// {
	// 	s = get_next_line(fd);
	// 	printf ("%s", s);
	// 	free(s);
	// 	s = NULL;
	// 	i++;
	// }
	system("leaks a.out");
	return (0);
}