/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:40:29 by francesca         #+#    #+#             */
/*   Updated: 2025/10/26 15:28:00 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.h"

PhoneBook::PhoneBook()
{
	this->contactsCount = 0;
}

PhoneBook::~PhoneBook()
{}

void PhoneBook::addContact()
{
    if (this->contactsCount == 8)
    {
        std::cout << "The library is full. I'm replacing the oldest contact." << std::endl;
        for (int i; i <= 7; i++)
        {
            this->Contacts[i] = this ->Contacts[i +1];
            contactsCount--;
        }
    }
    this->contacts[this->contactsCount].addContact();
	this->contactsCount++;
}
