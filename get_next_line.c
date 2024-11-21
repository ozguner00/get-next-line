#include "get_next_line.h"
#include <stdio.h>
char *ft_read_line(int fd)
{
	int read_byte;
	size_t total_read_byte = 0;
	char *line = NULL;
	char *buffer = malloc((BUFFER_SIZE) * sizeof(char));
	if(!buffer)
		return NULL;
	read_byte = read(fd,buffer,BUFFER_SIZE);

	while(read_byte <= -1 || read_byte > 0)
		{
			if(read_byte <= -1){
				free(buffer);
				free(line);
				return NULL;
			}
			total_read_byte += read_byte;
			line = ft_linecat(line,buffer,total_read_byte);
			if(ft_strchr(line,'\n'))
				return line;
			read_byte = read(fd,buffer,BUFFER_SIZE);
		}
		return line;
}

char *ft_linecat(char *line, char *buffer, size_t total_read_byte)
{	
    char *new_line;
    size_t i;
    size_t j;
    i = 0;
    new_line = malloc(total_read_byte + 1);  
    if (!new_line) 
         return NULL;  

    i = 0;
    if(line){
    while (line[i] != '\0') {
        new_line[i] = line[i];
        i++;
    }}

    j = 0;
    //printf("%s\n",line);
    while (total_read_byte > 0)
    {
        new_line[i++] = buffer[j++];
	total_read_byte--;
    }
    new_line[i] = '\0'; 
    // printf("%s\n",line);
    free(line);  

	return new_line;
}

char *get_next_line(int fd)
{
	char *print_line;
	static char *static_line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	print_line = ft_read_line(fd);
	return print_line;
	
}
