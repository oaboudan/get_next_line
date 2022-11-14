#include "get_next_line.h"

char    *get_line(char *str)
{
    int i;
    char *line;

    i = 0;
    while (str[i] != '\0' && str[i] != '\n' )
        i++;
    line = ft_substr(str,0,i);
    return line;
}
char    *next_line(char *str)
{
    int j;
    int i;
    char *next;

    i = 0;
    while (str[i] != '\0' && str[i] != '\n' )
        i++;
    next = (char *)malloc(ft_strlen(str) - i + 1);
    if (!next)
        return (NULL);
    j = 0;
    while (str[i])
        next[j++] = str[i++];
    next[j] = '\0';
    return next;
}
char    *read_line(char *str,int fd)
{
    char *buffer;
    int read_ret;

    read_ret = 1;
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    while (!ft_strchr(buffer,'\n') && read_ret != 0)
    {
        read_ret = read(fd,buffer,BUFFER_SIZE);
        if (read_ret = -1)
        {
            free(buffer);
            return NULL;
        }
        buffer[read_ret] = '\0';
        str = ft_strjoin(str,buffer);
    }
    free(buffer);
    return str;
}
char    *get_next_line(int fd)
{
    static char *line;
    char *str;
    if(fd < 0 || BUFFER_SIZE < 1)
        return  NULL;
    str = read_line(str,fd);
    if (!str)
        return NULL;
    line = get_line(str);
    str = next_line(str);
    return line;
}
int main()
{
    int fd ;
    fd = open("test.txt", O_CREAT, 0777);
    printf("%d",fd);
    char *line;
    printf("%s",get_next_line(fd));
    // while (line)
    // {
    //     printf("%s",line);
    //     line = get_next_line(fd);
    // }
    
}