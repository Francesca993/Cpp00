/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:46:10 by francesca         #+#    #+#             */
/*   Updated: 2025/10/26 13:53:59 by francesca        ###   ########.fr       */
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
