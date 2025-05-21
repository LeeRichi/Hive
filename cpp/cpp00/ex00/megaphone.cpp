/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:02:45 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/19 16:21:11 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void megaphone(string s) //std::string
{
    if (s)
		std::cout << s;
    else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
}

int main(int ac, char *av)
{
	// (void)ac;
	megaphone(av);
	return (0);
}