/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:20:44 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/06 01:13:18 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*tmp;

	i = -1;
	p = str;
	tmp = p;
	while (++i < n)
		*tmp++ = (unsigned char) c;
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	p = (char *)malloc((len + 1) * (sizeof(char)));
	if (p == 0)
		return (NULL);
	while (src[i])
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(const char *s, const char *s2)
{
	int		n;
	char	*tmp;
	char	*p;

	if (!s || !s2)
		return (NULL);
	n = ft_strlen(s);
	p = malloc(sizeof(char) * (n + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	tmp = p;
	while (*s)
		*tmp++ = *s++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (p);
}

char	*ft_strchr(const char *str, int c)
{
	c %= 128;
	if (c == 0)
		return ((char *)str + ft_strlen(str));
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
