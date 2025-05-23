/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:02:45 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/21 18:21:41 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

int	main(void)
{
	randomChump("Jay Stack Guy");
	Zombie *zmb = newZombie("Jared Heap Boi");
	if (!zmb)
		return 1;
	zmb->announce();
	delete(zmb);
	return (0);
}
