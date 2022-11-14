#include "get_next_line.h"

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
	if (s[i + start] = '\n')
		t[i++] = '\n';
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

char	*ft_strdup(char *str)
{
	char	*s;
	int		i;

	if (!str)
		return (NULL);
	s = (char *)malloc(ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	j;
	size_t	i;

	i = 0;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (++j < ft_strlen(s1))
		res[j] = s1[j];
	while (i < ft_strlen(s2))
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
