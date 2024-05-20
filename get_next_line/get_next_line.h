#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

#endif
