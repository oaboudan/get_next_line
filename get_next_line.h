#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*ft_strchr( char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup( char *s1);
size_t	ft_strlen( char *src);
char	*ft_substr(char *s, unsigned int start, size_t len);
#endif