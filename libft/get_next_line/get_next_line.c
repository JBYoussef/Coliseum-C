/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbofengo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:50:33 by jbofengo          #+#    #+#             */
/*   Updated: 2024/05/31 14:50:39 by jbofengo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract_line(char **rest)
{
	char	*line;
	char	*temp;
	char	*newline_pos;

	newline_pos = ft_strchr(*rest, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		line = ft_strjoin(*rest, "\n");
		temp = ft_strdup(newline_pos + 1);
		free(*rest);
		*rest = temp;
	}
	else
	{
		line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
	}
	return (line);
}

static char	*ft_read_append(int fd, char *rest)
{
	char			*buffer;
	char			*temp;
	int				n_bytes;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	n_bytes = read(fd, buffer, BUFFER_SIZE);
	while (n_bytes > 0)
	{
		buffer[n_bytes] = '\0';
		temp = rest;
		rest = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(rest, '\n'))
			break ;
		n_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{	
	static char		*rest;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (rest && ft_strchr(rest, '\n'))
		return (ft_extract_line(&rest));
	rest = ft_read_append(fd, rest);
	if (rest && ft_strchr(rest, '\n'))
		return (ft_extract_line(&rest));
	if (rest && *rest)
	{
		line = ft_strdup(rest);
		free(rest);
		rest = NULL;
		return (line);
	}
	free(rest);
	rest = NULL;
	return (NULL);
}
