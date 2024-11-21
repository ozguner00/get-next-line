#include "get_next_line.h"
#include <fcntl.h>
int main() {
 
   int  fd = open("test.txt", O_RDONLY); 
   char* main_line = get_next_line(fd);
    printf("Line: %s\n", main_line);
    
    return 0;
}
