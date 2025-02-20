/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpodratc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:26:19 by hpodratc          #+#    #+#             */
/*   Updated: 2025/02/20 14:51:20 by hpodratc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	d = (char *)dest;
	s = (char *)src;
	while (i < n)
	{
		d[i] = s[i];
		++i;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new_s = (char *)malloc(s1len + s2len + 1);
	if (new_s == NULL)
		return (NULL);
	ft_memcpy(new_s, s1, s1len);
	ft_memcpy(new_s + s1len, s2, s2len);
	new_s[s1len + s2len] = '\0';
	free(s1);
	return (new_s);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	i = 0;
	ch = (char) c;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		++i;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
