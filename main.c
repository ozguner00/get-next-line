#include "get_next_line.h"

int main() {
    int fd;
    char *line;

 
    fd = open("test.txt", O_RDONLY); 
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    line = get_next_line(fd);
    printf("Line: %s\n", line);
    
    close(fd); 
    return 0;
}
