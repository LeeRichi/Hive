/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:52:43 by chlee2            #+#    #+#             */
/*   Updated: 2024/05/07 14:14:07 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp_mem;

	temp_mem = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		temp_mem[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
