/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:14:38 by oaboudan          #+#    #+#             */
/*   Updated: 2022/11/21 16:49:19 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n' )
		i++;
	line = ft_substr(str, 0, i + 1);
	return (line);
}

char	*next_line(char *str)
{
	int		i;
	char	*next;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	next = ft_substr(str, i + 1, ft_strlen(str + i + 1));
	if (!next)
		return (NULL);
	free (str);
	return (next);
}

char	*read_line(char *str, int fd)
{
	char	*buffer;
	ssize_t	read_ret;

	read_ret = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && read_ret != 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_ret] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*stock;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = read_line(line, fd);
	if (!line)
		return (NULL);
	stock = get_line(line);
	line = next_line(line);
	return (stock);
}
