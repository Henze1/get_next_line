#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef READ_SIZE
#  define READ_SIZE 2048
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
void    *ft_memcpy(void *dest, const void *src, size_t n);
char    *ft_strjoin(char *s1, char const *s2);
char    *ft_strchr(const char *s, int c);

#endif
