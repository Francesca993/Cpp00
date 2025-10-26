/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:46:10 by francesca         #+#    #+#             */
/*   Updated: 2025/10/26 15:41:51 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::~Contact()
{
    this->firstName = "";
    this->lastName = "";
    this->nickName = "";
    this->phoneNumber = "";
    this->darkestSecret = "";
}

Contact::~Contact() 
{}

bool Contact::isValid() const {
    return !firstName.empty()
        && !lastName.empty()
        && !prefPet.empty()
        && !phoneNumber.empty()
        && !prefColor.empty();
}

static std::string readInfo(std::string type)
{
    std::string input;
    while (true)
    {
        std::cout << "Insert the" << type << ":" << std::endl;
        std::getline(std::cin, input);
        //inserire check degli input
    }
    return (input);
}

//std::cout << "tou push add" << std::endl;
void Contact::addContact()
{
    this->firstName = readInfo("First Name");
    this->lastName = readInfo("Last Name");
    this->nickName = readInfo("Nickname");
    this->phoneNumber = readNumber("Phone Number");
    this->darkestSecret = readInfo("darkest Secret");
    
    std::cout << "Contact create!" << std::endl;
}

std::string Contact::getFirstName() const
{
    return (this->firstName);
}

std::string Contact::getLastName() const
{
    return (this->lastName);
}

std::string Contact::getNickName() const
{
    return (this->nickName);
}

std::string Contact::getPhoneNumber() const
{
    return (this->phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
    return(this->darkestSecret);
}