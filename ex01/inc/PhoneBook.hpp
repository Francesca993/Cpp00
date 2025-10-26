/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:19:17 by francesca         #+#    #+#             */
/*   Updated: 2025/10/26 17:56:42 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
    private:
    int contactsCount;
    
    public:
    Contact contacts[8];
    PhoneBook();
        ~PhoneBook();
    
    void addContact();
    void displayCount() const;
    void displayContacts() const;
    void displayContact(int index) const;
};

#endif