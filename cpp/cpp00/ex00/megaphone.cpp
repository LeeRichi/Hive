/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:02:45 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/23 14:48:05 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void megaphone(std::string s)
{
	if (!s.empty())
	{
		for (char &c : s)
		{
			c = std::toupper(c);
		}
        std::cout << s;
	}
}

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for(int i = 1; i < ac; i++)
		{
			megaphone(av[i]);
		}
        std::cout << std::endl;
	}
	return (0);
}
