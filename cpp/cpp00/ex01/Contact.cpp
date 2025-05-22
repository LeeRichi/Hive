/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:58:16 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/22 12:03:26 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
    : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("")
{
}

Contact::Contact(
    std::string firstName, std::string lastName, std::string nickName,
    std::string phoneNumber, std::string darkestSecret
) :
    firstName(firstName),
    lastName(lastName),
    nickName(nickName),
    phoneNumber(phoneNumber),
    darkestSecret(darkestSecret)
{
}

Contact::~Contact()
{
}

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickName() const
{
    return nickName;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}

void Contact::printFull() const
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
