/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:16:06 by chlee2            #+#    #+#             */
/*   Updated: 2024/05/24 10:57:48 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
// char	*ft_strchar(char *content, char c);
char *ft_strchar(const char *s, int c);
size_t 	ft_strlen(char *s);
char	*ft_strjoin(char *a, char *b);
size_t	ft_check_line_break(char *s);
char	*ft_reverse_strchar(char *s, char c);
char	*ft_free(char **str);
char	*substr(char *s, size_t start, size_t len);

#endif
