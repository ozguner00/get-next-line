char *read_and_creat_for_line(int fd)
{
	int read_byte = 0;
	int total_read_byte = 0;
	char *buffer = malloc(BUFFER_SIZE) * sizeof(char));
	if(!buffer)
		return NULL;
	read_byte = 1;
	while(read_byte > 0)
	{	
		read_byte = read(fd,buffer,BUFFER_SIZE);
		if(read_byte == -1)
		{
			free(buffer);
			return NULL;
		}
		total_read_byte += read_byte;

	}
}

char *get_next_line(int fd)
{
	char *print_line;
	static char *static_line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;

	return print_line;
	//https://github.com/ramos21rodrigo/42porto.get-next-line/blob/master/get_next_line.c
}
