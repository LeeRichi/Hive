/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: LEECHI <LEECHI@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:15:38 by chlee2            #+#    #+#             */
/*   Updated: 2024/07/10 19:28:11 by LEECHI           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printchar(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	printstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (printstr("(null)"));
	while (*s)
	{
		if (printchar((int)*s) == -1)
			return (-1);
		count++;
		++s;
	}
	return (count);
}
