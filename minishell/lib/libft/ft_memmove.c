/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:06:09 by chlee2            #+#    #+#             */
/*   Updated: 2024/08/30 10:44:41 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (const unsigned char *)src;
	if (ptr_dst == ptr_src)
		return (dst);
	if (ptr_src < ptr_dst && ptr_dst < ptr_src + n)
	{
		ptr_src += n;
		ptr_dst += n;
		while (n--)
			*(--ptr_dst) = *(--ptr_src);
	}
	else
	{
		while (n--)
			*(ptr_dst++) = *(ptr_src++);
	}
	return (dst);
}
