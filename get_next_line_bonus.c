/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:16:59 by oaboudan          #+#    #+#             */
/*   Updated: 2022/11/21 23:45:25 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_l(char *str)
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
	str = NULL;
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
			buffer = NULL;
			return (free(str), str = NULL, NULL);
		}
		buffer[read_ret] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	buffer = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[10241];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 10241)
		return (NULL);
	str[fd] = read_line(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = get_l(str[fd]);
	str[fd] = next_line(str[fd]);
	return (line);
}
// int main()
// {
// 	int fd,fd1,fd2;
// 	fd = open("test1.txt",O_CREAT,0777);
// 	fd1 = open("test2.txt",O_CREAT,0777);
// 	fd2 = open("test.txt",O_CREAT,0777);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd1));
// 	printf("%s",get_next_line(fd1));
// 	printf("%s",get_next_line(fd1));
// 	printf("%s",get_next_line(fd1));
// 	printf("%s",get_next_line(fd));
// 	//printf("%s",get_next_line(fd1));
// 	printf("%s",get_next_line(fd2));
// 	printf("%s",get_next_line(fd2));
// }
// int main()
// {
// 	int fd = open ("sss", O_RDONLY);
// 	int fd1 = open ("ss", O_RDONLY);
// 	char *s = get_next_line(fd);
// 	char *s1 = get_next_line(fd1);

// 	while(1)
// 	{
// 		printf("%s", s);
// 		free(s);
// 		s = get_next_line(fd);
// 		printf("%s", s1);
// 		free(s1);
// 		s1 = get_next_line(fd1);
// 		if (!s)
// 			break;
// 	}
// }