#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char *get_next_line(int fd);
char *ft_linecat(char *line, char *buffer, size_t total_read_byte, size_t buffer_read_size);
char	*ft_strjoin(char *s1, char *s2);

#endif
