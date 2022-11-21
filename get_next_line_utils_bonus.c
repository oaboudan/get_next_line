/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:25:15 by oaboudan          #+#    #+#             */
/*   Updated: 2022/11/22 00:05:13 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*t;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	t = (char *)malloc(sizeof(char) * (len + 2));
	if (!t)
		return (NULL);
	while (i < len && s[start] && start < ft_strlen(s))
	{
		t[i] = s[i + start];
		i++;
	}
	t[i] = '\0';
	return (t);
}

size_t	ft_strlen(char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*p;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	j;
	size_t	i;
	size_t	size_s1;
	size_t	size_s2;

	i = 0;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	res = (char *)malloc(size_s1 + size_s2 + 1);
	if (!res)
		return (NULL);
	while (++j < size_s1)
		res[j] = s1[j];
	while (i < size_s2)
		res[j++] = s2[i++];
	res[j] = '\0';
	return ((free(s1)), (s1 = NULL), (res));
}

int	ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (1);
	size = ft_strlen(s);
	while (i <= size)
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}
