/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:19:17 by francesca         #+#    #+#             */
/*   Updated: 2025/10/27 08:02:14 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <sstream>   // <-- NECESSARIO per std::istringstream

class PhoneBook
{
    private:
    int contactsCount;
    Contact contacts[8];
    
    public:
    PhoneBook();
        ~PhoneBook();
    
    void CheackAddContact();
    int  displayCount() const;
    void printTable() const;
    void searchContact(int index) const;
    void searchContacts() const;
    static std::string formatColumn(const std::string& value);
};

#endif