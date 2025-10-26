/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:30:53 by francesca         #+#    #+#             */
/*   Updated: 2025/10/26 17:59:39 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"

int main()
{
    std::string     command;
    PhoneBook PhoneBook;

    while (true)
    {
        std::cout << "Enter a command: ADD, SEARCH and EXIT" << std::endl;
        // Taking input from cin stream(standard
        // input stream) and storing it in command
        if (!std::getline(std::cin, command)) 
        {
            // EOF/errore input: nessun comando possibile -> termina in silenzio
            break;
        }
        // Convert command to uppercase
		for (size_t i = 0; i < command.length(); ++i)
			command[i] = std::toupper(command[i]);
        if (command == "ADD")
        {
            PhoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            std::cout << "tou push SEARCH" << std::endl;    
        }
        else if (command == "EXIT")
            break;
        else
        {
            std::cout << "Invalid command. Use ADD, SEARCH or EXIT" << std::endl;
        }
            
    }
    return (0);
            
}