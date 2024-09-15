/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:13:47 by chlee2            #+#    #+#             */
/*   Updated: 2024/09/15 15:42:41 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
#define CONSTANTS_H

# define BLOCK_SIZE 64

//temp
# define AMOUNT_OF_IMGS 5

typedef enum s_char
{
	SPACE = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
} t_char;

typedef enum s_img
{
	W,
	G,
	P,
	C,
	E
} t_img;

#endif
