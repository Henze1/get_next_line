#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUFF 1024
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

#endif
