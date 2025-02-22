/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:26:03 by hpodratc          #+#    #+#             */
/*   Updated: 2025/02/20 19:02:57 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff;
	static char	str[BUFFER_SIZE + 1];
	ssize_t		read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff)
		buff = ft_strdup("");
	read_size = read(fd, str, BUFFER_SIZE);
	while (read_size > 0)
	{
		str[read_size] = '\0';
		buff = ft_strjoin(buff, str);
		if (ft_strchr(str, '\n'))
			break ;
		read_size = read(fd, str, BUFFER_SIZE);
	}
	if (read_size == -1 || (read_size == 0 && (!buff || buff[0] == '\0')))
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	return (extract_line(&buff));
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(s) + 1;
	dest = (char *)malloc(len);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, len);
	return (dest);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		++i;
	}
	sub[len] = '\0';
	return (sub);
}

char	*extract_line(char **buff)
{
	char	*line;
	char	*new_buff;
	int		i;

	i = 0;
	while ((*buff)[i] && (*buff)[i] != '\n')
		i++;
	if ((*buff)[i] == '\n')
		line = ft_substr(*buff, 0, i + 1);
	else
		line = ft_strdup(*buff);
	if ((*buff)[i] == '\n')
		new_buff = ft_strdup(*buff + i + 1);
	else
		new_buff = NULL;
	free(*buff);
	*buff = new_buff;
	return (line);
}
/*
int	main(void)
{
	const char	*FILE;
	int		fd;
	char		*line;

	FILE = "1char.txt";
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

	// write(1, "\n", 1);

	// line = get_next_line(fd);
 	// write(1, line, ft_strlen(line));
	//	  free(line);

	// line = get_next_line(fd);
	// write(1, line, ft_strlen(line));
	free(line);

	close(fd);
	return (0);
}*/
