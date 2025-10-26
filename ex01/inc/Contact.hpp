/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:20:42 by francesca         #+#    #+#             */
/*   Updated: 2025/10/26 13:53:42 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
    private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    
    public:
    // Costruttore di default: lascia le stringhe vuote (stato "pulito")
    Contact();
		~Contact();
        
    // Create contact
	void	createContact();
    bool    isValid();
    
    // Setters: permettono di impostare i campi da fuori in modo controllato
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getNickName() const;
    const std::string& getPhoneNumber() const;
    const std::string& getDarkestSecret() const;
    // Utility: vero se TUTTI i campi sono non vuoti (utile per validazioni)
    bool isValid() const;
};

#endif