#include "get_next_line.h"
#include <stdio.h>

char	*ft_read_line(int fd)
{
	int		read_byte;
	size_t	total_read_byte;
	char	*line;
	char	*buffer;

	total_read_byte = 0;
	line = NULL;
	buffer = malloc((BUFFER_SIZE) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_byte = read(fd, buffer, BUFFER_SIZE);
	while (read_byte <= -1 || read_byte > 0)
	{
		if (read_byte <= -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		total_read_byte += read_byte;
		line = ft_linecat(line, buffer, total_read_byte, read_byte); // ???
		if (ft_strchr(line, '\n'))
		{
			free(buffer);
			return (line);
		}
		read_byte = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (line);
}
char	*ft_edit_line(char *line)
{
	static char	*remaining = NULL;
	char		*final_line;
	char		*newline_pos;

	if (remaining)
	{
		// printf("remaining \t:%s\n",remaining);
		line = ft_linecat2(remaining, line, ft_strlen(remaining)
				+ ft_strlen(line), ft_strlen(line));
		// printf("line \t:%s\n",line);
		remaining = NULL;
	}
	newline_pos = ft_strchr(line, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		free(remaining);
		remaining = ft_strdup(newline_pos + 1);
	}
	final_line = ft_strdup(line);
	free(line);
	return (final_line);
}

char	*ft_linecat(char *line, char *buffer, size_t total_read_byte,
		size_t buffer_read_size)
{
	char	*new_line;
	size_t	i;
	size_t	j;

	i = 0;
	new_line = malloc(total_read_byte + 1); // ??
	if (!new_line)
		return (NULL);
	i = 0;
	if (line)
	{
		while (line[i] != '\0')
		{
			new_line[i] = line[i];
			i++;
		}
	}
	j = 0;
	while (buffer_read_size > 0) // total_read_byte göre atama yap
	{
		new_line[i++] = buffer[j++];
		buffer_read_size--;
	}
	new_line[i] = '\0';
	free(line);
	return (new_line);
}
char	*ft_linecat2(char *line, char *buffer, size_t total_read_byte,
		size_t buffer_read_size)
{
	char	*new_line;
	size_t	i;
	size_t	j;

	i = 0;
	new_line = malloc(total_read_byte + 1); // ??
	if (!new_line)
		return (NULL);
	i = 0;
	if (line)
	{
		while (line[i] != '\0')
		{
			new_line[i] = line[i];
			i++;
		}
	}
	j = 0;
	while (buffer_read_size > 0) // total_read_byte göre atama yap
	{
		new_line[i++] = buffer[j++];
		buffer_read_size--;
	}
	new_line[i] = '\0';
	free(line);
	free(buffer);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char	*print_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	print_line = ft_read_line(fd); // ??
	if (print_line == NULL)
		return (NULL);
	print_line = ft_edit_line(print_line);
	print_line = ft_strjoin(print_line, "\n");
	return (print_line);
}
