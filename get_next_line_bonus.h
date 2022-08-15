/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 04:19:30 by nchoo             #+#    #+#             */
/*   Updated: 2022/08/15 12:29:13 by nchoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_SIZE
#  define FD_SIZE 1024
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(const char *s, const char *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif
