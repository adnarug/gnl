/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/10 17:29:16 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./get_next_line.h"
#include	<stdio.h>
#include 	<fcntl.h>


char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*rest;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	get_line(fd, &rest);
	next_line = split_next_line(rest);
	split_remainder(&rest);
	return (next_line);
}

char *split_next_line(char *rest)
{
	char	*new_line;
	char	*line_break_point;
	char	*eof_point;
	int		i;

	i = 0;
	while (rest[i] != '\n' && rest[i] != '\0')// zero here?
		i++;
	i = 0;
	new_line = malloc(sizeof(char) * i + 2);
	line_break_point = strchr(rest, '\n');
	eof_point = strchr(rest, '\0');
	while(((line_break_point != NULL) || (eof_point != NULL)) && ((rest[i] != '\n') && (rest[i] != '\0')))
	{
		new_line[i] = rest[i]; 
		i++;
	}
	new_line[i] = '\n';
	new_line[i + 1] = '\0';
	return (new_line);
}

void split_remainder(char **rest)
{
	unsigned int		i; 
	char				*remainder;
	int					d;

	i = 0;
	d = 0;
	while (**rest != '\n' && **rest != '\0')
		*rest += 1;
	*rest += 1;
	i = strlen(*rest);
	if (i == 0)
		return ;
	remainder = malloc(sizeof(char) * i + 2);
	if (remainder == NULL)
		return ;
	strcpy(remainder, *rest);
	remainder[i] = '\0';
	*rest = remainder;
}

void	get_line(int fd, char **rest)
{
	char	*new_line;
	int		read_result;
	int		buf_iterations;

	read_result = 1;
	buf_iterations = 1;
	new_line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(new_line == NULL)
		return ;
	while ((ft_strchr(*rest, '\n') == NULL) && read_result != 0)
	{
		read_result = read(fd, new_line, BUFFER_SIZE);
		if(read_result == -1)
		{
			free(new_line);
			new_line = NULL;
			return ;
		}
		if(read_result == 0)
		{
			line_merge(new_line, &*rest);
			break;
		}
		buf_iterations++;
		new_line[buf_iterations * BUFFER_SIZE] = '\0';
		line_merge(new_line, &*rest);
		bzero(new_line, BUFFER_SIZE);
	}
	free(new_line);
	new_line = NULL;
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
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);
	s = get_next_line(fd);
	printf("%s", s);

	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	//s = NULL;
	// printf("%s", get_next_line(fd));
	//printf("%s", ft_strjoin("\n\n", buffer));
	system("leaks a.out");
	return (0);
}