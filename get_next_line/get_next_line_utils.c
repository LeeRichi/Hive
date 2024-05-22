/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:15:52 by chlee2            #+#    #+#             */
/*   Updated: 2024/05/22 16:37:28 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *s)
{
    size_t  i;

    i = 0;
    while(s[i])
        i++;
    return (i);
}

char	*ft_strchar(char *content, char c)
{
	size_t	i;

	if (ft_strlen(content) == 0)
		return (NULL);
	i = 0;
	while (content[i])
	{
		if (content[i] == c)
			return (content + i);
		i++;
	}
	return (content);
}

static size_t ft_count_len(char *a, char *b)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (a[i])
		i++;
	j = 0;
	while (b[j])
		j++;
	return (i + j);
}

size_t	ft_strlen_with_c(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *a, char *b)
{
	size_t	i;
	size_t	j;
	char	*new_str;
	size_t	len;

    if (!a)
    {
        a = malloc(sizeof(char));
        if (!a)
            return (NULL);
        a[0] = 0;
    }
	len = ft_count_len(a, b);
	new_str = malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = -1;
	while (a[++i])
		new_str[i] = a[i];
	j = -1;
	while (b[++j])
		new_str[i + j] = b[j];
	new_str[i + j] = 0;
    //free(a); //necessary?
	return (new_str);
}

size_t	ft_check_line_break(char *s)
{
	size_t	i;

	//printf("test\n");
	//printf("content: %s\n", s);
	i = 0;
	while (s[i++])
	{
		if (s[i] == '\n')
			return (1);
	}
	return (0);
}

char	*ft_reverse_strchar(char *s, char c)
{
	size_t	i;
	char	*new_str;

	if (!s)
		return (NULL);
	i = 0;
	while(s[i] && s[i] != c)
		i++;
	new_str = malloc((i + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[i] = '\0';
	while (i > 0)
	{
		--i;
		new_str[i] = s[i];
	}
	s = ft_strchar(s, c);
	return (new_str);
}


// int main(void)
// {
// 	char *rich;

// 	rich = "agrwgrwrwb,[,bbwrbcccc";
// 	printf("%s\n", ft_reverse_strchar(rich, '['));
// }
