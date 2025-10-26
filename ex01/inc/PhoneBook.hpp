/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:19:17 by francesca         #+#    #+#             */
/*   Updated: 2025/10/26 14:46:15 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>
# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
    private:
    Contact contacts[8];
    int contactsCount;

    public:
    PhoneBook();
        ~PhoneBook();
    
    void addContact();
    void displayCount() const;
    void displayContacts() const;
    void displayContact(int index) const;
};

#endif