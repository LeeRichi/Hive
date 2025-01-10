/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:45:13 by chlee2            #+#    #+#             */
/*   Updated: 2025/01/10 18:12:13 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include	<string.h>
# include	<errno.h>
# include "get_next_line/get_next_line.h"

//for flood_fill
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlcat(char *dst,
			const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst,
			const char *src, size_t dstsize);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t n);
int		ft_atoi(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);
int		ft_atoll(char *str);
char	*ft_strrchr(const char *s, int c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strcmp(const char *s1, const char *s2);

void	flood_fill(char **tab, t_point size, t_point begin);
void	rich_flood_fill(char **tab, t_point size, t_point begin);

//ft_printf_packages
int		ft_printf(const char *format, ...);
int		printchar(char c);
int		printstr(char *s);
int		printnbr(long n, int base);
int		printnbr_butx(long n, int base);
int		printnbr_foraddress(unsigned long n, int base);
int		printaddress(unsigned long something);

//new for pipex
int		is_empty_or_whitespace(char *str);

//new for minishell
void	*ft_realloc(void *ptr, size_t size);


#endif
