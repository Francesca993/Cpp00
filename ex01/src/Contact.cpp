/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:46:10 by francesca         #+#    #+#             */
/*   Updated: 2025/10/26 21:23:25 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    this->firstName = "";
    this->lastName = "";
    this->nickName = "";
    this->phoneNumber = "";
    this->darkestSecret = "";
}

Contact::~Contact() 
{}

/*
// Ritorna true se s è vuota OPPURE composta solo da whitespace
*/
static bool isAllSpaces(const std::string& s) 
{
    if (s.empty()) 
    return (true); // evita vuoto
     for (std::string::size_type i = 0; i < s.size(); ++i)
    {
        unsigned char uc = static_cast<unsigned char>(s[i]);
        if (!std::isspace(uc)) 
            return (false);
    }
    return (true);
}

static std::string readInfo(std::string type)
{
    std::string input;
    while (true)
    {
        std::cout << "Insert the " << type << ":" << std::endl;
        std::getline(std::cin, input);
        if (!isAllSpaces(input))
			break ;
		std::cout << "The " << type << " cannot be empty or only spaces." << std::endl;
    }
    return (input);
}

// Ritorna true se s è non-vuota E tutte cifre
static bool isAllDigits(const std::string& s) 
{
     if (s.empty()) 
        return (false);
    for (std::string::size_type i = 0; i < s.size(); ++i)
    {
        unsigned char uc = static_cast<unsigned char>(s[i]);
        if (!std::isdigit(uc)) return false;
    }
    return (true);
}

static std::string readNumber(std::string type)
{
    std::string input;
    while (true)
    {
        std::cout << "Insert the " << type << ":" << std::endl;
        std::getline(std::cin, input);
        if (isAllDigits(input))
			break ;
        std::cout << "The " << type << " must contain digits only and cannot be empty." << std::endl;
	}
    return (input);
}

void Contact::addContact()
{
    this->firstName = readInfo("First Name");
    this->lastName = readInfo("Last Name");
    this->nickName = readInfo("Nickname");
    this->phoneNumber = readNumber("Phone Number");
    this->darkestSecret = readInfo("darkest Secret");
    
    // Debug
    // std::cout << this->firstName << std::endl;
    // std::cout << this->lastName << std::endl;
    // std::cout << this->phoneNumber << std::endl;
    // std::cout << this->nickName << std::endl;
    // std::cout << this->darkestSecret << std::endl;
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