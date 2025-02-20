#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff;
    static char	str[BUFFER_SIZE + 1];
    ssize_t		read_size;

	buff = malloc(1);
	while ((read_size = read(fd, str, BUFFER_SIZE)) > 0)
	{
		if (!ft_strchr(str, '\n'))
			buff = ft_strjoin(buff, str);
		else
		{
            buff = ft_strjoin(buff, ft_strchr(str, '\n'));
            return (buff);
		}
	}
    str[read_size] = '\0';
	return (buff);
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
	write(1, line, ft_strlen(line));
	free(line);

    write(1, "\n", 1);

	line = get_next_line(fd);
	write(1, line, ft_strlen(line));
    free(line);

	close(fd);
	return (0);
}
