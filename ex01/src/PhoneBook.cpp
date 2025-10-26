/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:40:29 by francesca         #+#    #+#             */
/*   Updated: 2025/10/26 17:56:31 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

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
        for (int i = 0; i <= 7; i++)
        {
            this->contacts[i] = this ->contacts[i +1];
            contactsCount--;
        }
    }
    this->contacts[this->contactsCount].addContact();
	this->contactsCount++;
}
