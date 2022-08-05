/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:18:26 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/06 01:14:38 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*res;
	size_t	i;

	if (n >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	i = (n * size);
	res = malloc(n * size);
	if (!res)
		return (NULL);
	ft_memset(res, 0, i);
	return (res);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (p = ft_calloc(1, sizeof(char)));
	else if (len > (ft_strlen(s) - start))
		p = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (i < len && s[i + start])
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static char	*next_line(char **s)
{
	int	i;
	char	*ret;
	char	*tmp;

	i = 0;
	while ((*s)[i] && (*s)[i] != '\n')
		i++;
	if ((*s)[i] == '\n')
	{
		ret = ft_substr(*s, 0, i + 1);
		tmp = ft_strdup(*s + i + 1);
		free(*s);
		*s = tmp;
	}
	else
	{
		ret = ft_strdup(*s);
		free(*s);
		*s = NULL;
	}
	return (ret);
}

static void read_file(int fd, char *buffer, char **s, int n)
{
	char	*tmp;
	
	while (n > 0)
	{
		buffer[n] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(s[fd], buffer);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
		n = read(fd, buffer, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	static char		*s[FD_SIZE];
	char 			*buffer;
	ssize_t 		n;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	n = read(fd, buffer, BUFFER_SIZE);
	read_file(fd, buffer, s, n);
	free(buffer);
	if (n < 0)
		return (NULL);
	if (!n && (!s[fd] || !*s[fd]))
		return (NULL);
	return (next_line(&s[fd]));
}
