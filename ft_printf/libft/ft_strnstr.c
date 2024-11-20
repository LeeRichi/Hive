/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:03:43 by chlee2            #+#    #+#             */
/*   Updated: 2024/05/07 15:27:47 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;

	if (!haystack && !len)
		return ("");
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		j = 0;
		while (*(haystack + j) == *(needle + j) && *(needle + j) && j <= len)
		{
			if (!*(needle + j + 1))
			{
				return ((char *)haystack);
			}
			j++;
		}
		haystack++;
	}
	return (NULL);
}
