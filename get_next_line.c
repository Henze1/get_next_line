#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buff[BUFF];

	return (NULL);
}

int	main(void)
{
	const char	*FILE;
	int		fd;
	char		*line;
	
	FILE = "get_next_line.c";
	fd = open(FILE, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		write(1, line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
