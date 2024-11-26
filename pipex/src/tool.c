/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:30:00 by chlee2            #+#    #+#             */
/*   Updated: 2024/11/26 16:30:24 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*rev_str(char *str)
{
	int		len;
	char	*new_str;
	int		i;

	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (len != 0)
	{
		new_str[i] = str[len - 1 - i];
		i++;
		len--;
	}
	new_str[i] = '\0';
	return (new_str);
}
