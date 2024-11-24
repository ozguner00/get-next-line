#include "get_next_line.h"
#include <fcntl.h>
int main() {
 
   int  fd = open("test.txt", O_RDONLY); 
   char* main_line;
  main_line =  get_next_line(fd);
  printf("%s", main_line);
  free(main_line);
   main_line =  get_next_line(fd);
  printf("%s", main_line);
  free(main_line);
  
    return 0;
}
