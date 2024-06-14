#include <libc.h>
#include "get_next_line_bonus.h"
int main()
{
	int fd;
    int fd2;

    fd = open("src", O_RDONLY);
	fd2 = open("src2", O_RDONLY);	
	char *line;
	char *line2;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{

		printf("%s", line);
			break ;
		}
		printf("%s", line);
		free(line);

		line2 = get_next_line(fd2);
		if (!line2)
		{

		printf("%s", line2);
			break ;
		}
		printf("%s", line2);
		free(line2);

	}

	close(fd);
	close(fd2);
	return 0;
}
