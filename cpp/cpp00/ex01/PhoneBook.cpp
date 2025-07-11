/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:58:16 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/23 19:08:33 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : count(0), nextIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}

int PhoneBook::getCount() const
{
    return count;
}

//in const std::string& phoneNumber), '&' passes a reference to the original string without copying it
static bool isValidPhoneNumber(const std::string& phoneNumber)
{
    for (size_t i = 0; i < phoneNumber.length(); ++i) {
        if (!std::isdigit(phoneNumber[i]) && phoneNumber[i] != '+' && phoneNumber[i] != '-' && phoneNumber[i] != ' ') {
            return false;
        }
    }
    return true;
}

void PhoneBook::addContact()
{
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

    std::cout << "Enter first name: ";
    if (!std::getline(std::cin, firstName)) return;
    if (firstName.empty())
    {
        std::cout << "FirstName cannot be empty!" << std::endl;
        return;
    }
    std::cout << "Enter last name: ";
    if (!std::getline(std::cin, lastName)) return;
    if (lastName.empty())
    {
        std::cout << "LastName cannot be empty!" << std::endl;
        return;
    }
    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, nickName)) return;
    if (nickName.empty())
    {
        std::cout << "NickName cannot be empty!" << std::endl;
        return;
    }
    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, phoneNumber)) return;
    if (!isValidPhoneNumber(phoneNumber))
    {
        std::cout << "Invalid phone number format." << std::endl;
        return;
    }
    if (phoneNumber.empty())
    {
        std::cout << "PhoneNumber cannot be empty!" << std::endl;
        return;
    }
    std::cout << "Enter darkest secret: ";
    if (!std::getline(std::cin, darkestSecret)) return;
    if (darkestSecret.empty())
    {
        std::cout << "DarkestSecret cannot be empty!" << std::endl;
        return;
    }

    contacts[nextIndex] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);

    nextIndex = (nextIndex + 1) % MAX_CONTACTS;
    if (count < MAX_CONTACTS)
        count++;
}

//setw = set width
static void printField(const std::string& str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
}

static void printContactSummary(const Contact& contact, int index)
{
    //If index is shorter than 10 characters (like a small number), it will be padded with spaces on the left by default to fill the width.
    std::cout << std::setw(10) << index << "|";
    printField(contact.getFirstName());
    std::cout << "|";
    printField(contact.getLastName());
    std::cout << "|";
    printField(contact.getNickName());
    std::cout << std::endl;
}

void PhoneBook::searchContact() const
{
    if (count == 0)
    {
        std::cout << "Phonebook is empty" << std::endl;
        return;
    }

    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    for (int i = 0; i < count; i++)
    {
        printContactSummary(contacts[i], i);
    }

    std::cout << "Enter the index of the contact to display details: ";
    int index = -1;
    std::string line;
    if (!std::getline(std::cin, line))
        return;
 
    try
    {
        index = std::stoi(line);
    }
    catch (...)
    {
        std::cout << "Invalid input." << std::endl;
        return;
    }

    if (index < 0 || index >= count)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    contacts[index].printFull();
}
