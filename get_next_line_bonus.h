/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaboudan <oaboudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:17:02 by oaboudan          #+#    #+#             */
/*   Updated: 2022/11/21 18:42:22 by oaboudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		ft_strchr( char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup( char *s1);
size_t	ft_strlen( char *src);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif