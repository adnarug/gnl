/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/06/16 14:15:18 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./get_next_line.h"
#include	<stdio.h>
#include 	<fcntl.h>

/*	- Read until the read line contains \n or \0, then put it all into unsorted line
	- Take out the next line from unsorted line and return it (leak to be freed in main)
	- Take out the remainder after \n and put it at the start of unsorted line for further use*/
char	*get_next_line(int fd)
{
	static char	*unsorted_line;
	char		*next_line;
	int			last_read;

	if(read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	last_read = 0;
	next_line = NULL;
	read_until_nl(fd, &unsorted_line, &last_read);
	if(unsorted_line == NULL)
		return (NULL);
	else if (*unsorted_line == '\0')
	{
		gn_free_buf(&unsorted_line);
		return (NULL);
	}
	next_line = split_next_line(unsorted_line, &last_read);
	unsorted_line = split_remainder(unsorted_line);
	return(next_line);
}

void	read_until_nl(int fd, char **unsorted_line, int *last_read)
{
	char	*new_line;
	int		read_result;

	read_result = 1;
	new_line = NULL;
	new_line = malloc(sizeof(char) * BUFFER_SIZE + 1); /// +1
	if(new_line == NULL)
		return ;
	while ((ft_strchr(*unsorted_line, '\n') == NULL) && read_result > 0)
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
			*unsorted_line = line_merge(new_line, *unsorted_line);
			break;
		}
		// if (*new_line == '\n')
		// {
		// 	**unsorted_line = '\n';
		// 	break;
		// }
		new_line[BUFFER_SIZE] = '\0';
		*unsorted_line = line_merge(new_line, *unsorted_line);
		bzero(new_line, BUFFER_SIZE);
	}
	free(new_line);
	new_line = NULL;
}

char *split_next_line(char *unsorted_line, int *last_read)
{
	char	*new_line;
	int		i;

	i = 0;
	//while (strchr(unsorted_line, '\n') != NULL && unsorted_line[i] != '\n')// zero here?
	while (unsorted_line[i] != '\n' && unsorted_line[i] != '\0')
		i++;
	new_line = malloc(sizeof(char) * i + 2);
	if (new_line == NULL)
		return (NULL);
	i = 0;
	while(((strchr(unsorted_line, '\n') != NULL) || (strchr(unsorted_line, '\0') != NULL)) && ((unsorted_line[i] != '\n') && (unsorted_line[i] != '\0')))
	{
		new_line[i] = unsorted_line[i]; 
		i++;
	}
	if (*last_read == 0)
	{
		new_line[i] = '\n';
		new_line[i + 1] = '\0';
	}
	return (new_line);
}

char *split_remainder(char *unsorted_line)
{
	unsigned int		i; 
	char				*remainder;

	i = 0;
	while (unsorted_line[i] != '\n' && unsorted_line[i] != '\0')
		i++;
	if (unsorted_line[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	remainder = malloc(sizeof(char) * i);
	if (remainder == NULL)
		return (NULL);
	strcpy(remainder, &unsorted_line[i]);
	free(unsorted_line);
	unsorted_line = NULL;
	return(remainder);
}


// int	main(void)
// {
//  	char	*s;
//  	int fd;
//  	fd = 0;
	 
//  	fd = open("/Users/pguranda/Projects/gnl_1/text", O_RDONLY);
//  	s = get_next_line(fd);
//  	printf ("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
//  	printf ("%s", s);
// 	// s = get_next_line(fd);
// 	// printf ("%s", s);
// 	// s = get_next_line(fd);
// 	// printf ("%s", s);
// 	// s = get_next_line(fd);
// 	// printf ("%s", s);
//  	//printf ("number of chars %lu\n", strlen(s));
//  	// s = get_next_line(fd);
// 	// printf ("%s", s);
// 	// s = get_next_line(fd);
// 	// printf ("%s", s);
// 	system("leaks a.out");
// 	return (0);
// }