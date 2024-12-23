#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*main_line;

	fd = open("test.txt", O_RDONLY);
	main_line = get_next_line(fd);
	printf("%s", main_line);
	free(main_line);
	main_line = get_next_line(fd);
	printf("%s", main_line);
	free(main_line);
	main_line = get_next_line(fd);
	printf("%s", main_line);
	free(main_line);
	main_line = get_next_line(fd);
	printf("%s", main_line);
	free(main_line);
	main_line = get_next_line(fd);
	printf("%s", main_line);
	free(main_line);
	main_line = get_next_line(fd);
	printf("%s", main_line);
	free(main_line);
	main_line = get_next_line(fd);
	printf("%s", main_line);
	free(main_line);
	main_line = get_next_line(fd);
	printf("%s", main_line);
	free(main_line);
	main_line = get_next_line(fd);
	printf("%s", main_line);
	free(main_line);
	return (0);
}
