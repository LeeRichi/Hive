/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:58:16 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/22 11:52:22 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();
    Contact(std::string firstName, std::string lastName, std::string nickName,
            std::string phoneNumber, std::string darkestSecret);
    ~Contact();

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    void printFull() const;
};

#endif
