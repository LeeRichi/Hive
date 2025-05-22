/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:58:16 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/22 12:18:26 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nEOF detected. Exiting...\n";
            break;
        }

        if (command == "ADD")
        {
            phoneBook.addContact();
            if (std::cin.eof())
            {
                std::cout << "EOF detected. Exiting...\n";
                break;
            }
        }
        else if (command == "SEARCH")
        {
            if (phoneBook.getCount() == 0)
                std::cout << "Phonebook is empty\n";
            else
            {
                phoneBook.searchContact();
                if (std::cin.eof())
                {
                    std::cout << "EOF detected. Exiting...\n";
                    break;
                }
            }
        }
        else if (command == "EXIT")
        {
            std::cout << "Closing phonebook..." << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid command" << std::endl;
        }
    }

    return 0;
}
