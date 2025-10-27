/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:40:29 by francesca         #+#    #+#             */
/*   Updated: 2025/10/27 08:20:15 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
#include <iomanip> 

// Create and reset PhoneBook
PhoneBook::PhoneBook()
{
	this->contactsCount = 0;
}

// Destroy
PhoneBook::~PhoneBook()
{}

// Add a contact on the PhoneBook
void PhoneBook::CheackAddContact()
{
   if (contactsCount == 8) {
        std::cout << "The library is full. I'm replacing the oldest contact.\n";
        // Shift 0<-1, 1<-2, ..., 6<-7
        for (int i = 0; i < 7; ++i)
            contacts[i] = contacts[i + 1];

        // Inserisci il nuovo in coda e termina
        contacts[7].addContact();
        return;                 // contactsCount resta 8
    }
    // Caso non pieno: append
    contacts[contactsCount].addContact();
    contactsCount++;
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

//cerca signolo contatto per index
void PhoneBook::searchContact(int index) const
{
    std::cout << "Firs tName: " << this->contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
    std::cout << "NickName: " << this->contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
}

//mostra il count dei contatti
int PhoneBook::displayCount() const
{
    return (this->contactsCount);
}


void PhoneBook::searchContacts() const
{
    std::string idx;
    if (this->contactsCount == 0)
    {
        std::cout << "The phonebook is empty. Add at least one contact first." << std::endl;
        return;
    }
    this->printTable();
    // Richiesta dell'indice
    std::cout << "Enter the index from 0 to " << this->contactsCount -1 << ":" << std::endl;
    std::getline(std::cin, idx);
    // Check che sia un numero
    if (!isAllDigits(idx))
    {
        std::cout << "Invalid input. Please type digits only." << std::endl;
        return;
    }
    //Conversione sicura e controllo sul range
    std::istringstream iss(idx);
    int index = -1;
    iss >> index;

    if (index < 0 || index >= this->contactsCount) 
    {
        std::cout << "Index out of range." << std::endl;
        return;
    }
    this->searchContact(index);
    
}
/*
Cosa fa std::istringstream iss(input);
Crea uno stream di input che legge i caratteri dalla stringa input
(quella che hai letto con std::getline).
Puoi immaginarlo come una “versione finta” di std::cin, ma che pesca dalla
tua stringa invece che dalla tastiera.
 
Cosa fa iss >> index;
Usa l’operatore di estrazione >> per provare a leggere un intero da quello stream e 
metterlo dentro index.

Il parser di >>:
Salta gli spazi iniziali (spazi, tab, newline).
Legge un eventuale segno (+ o -).
Legge una sequenza di cifre decimali (0–9).
Si ferma al primo carattere che non appartiene alla sequenza valida.
Se non riesce a leggere neanche una cifra valida (per esempio, "", "abc", " + "), lo 
stream mette il flag failbit e non modifica index (rimane a -1 nell’esempio).
Se legge correttamente almeno un numero (es. "12abc"), converte la parte valida (12) e si 
ferma prima di a. In questo caso index diventa 12.
*/

// Regola del subject: colonne da 10 caratteri, right-aligned.
// Se il testo supera 10, si tronca a 9 e il 10° carattere diventa '.'
std::string PhoneBook::formatColumn(const std::string& value)
{
    if (value.size() > 10) {
        std::string truncated = value.substr(0, 9);
        truncated.push_back('.');
        return (truncated); // lunghezza 10
    }
    return (value); // verrà allineata a destra con setw(10)
}

void PhoneBook::printTable() const
{
    // Intestazioni: larghezza 10, allineamento a destra
    std::cout << std::right
        << std::setw(10) << "INDEX" << "|" 
        << std::setw(10) << "FIRST NAME" << "|" 
        << std::setw(10) << "LAST NAME" << "|" 
        << std::setw(10) << "NICKNAME" << "|" << std::endl;
    
    // Separatore
    std::cout << std::string(10, '-') << "+"
              << std::string(10, '-') << "+"
              << std::string(10, '-') << "+"
              << std::string(10, '-') << "|" << std::endl;

    // Righe
    for (int i = 0; i < this->contactsCount; ++i) {
        std::cout << std::right
                  << std::setw(10) << i << "|"
                  << std::setw(10) << PhoneBook::formatColumn(this->contacts[i].getFirstName()) << "|"
                  << std::setw(10) << PhoneBook::formatColumn(this->contacts[i].getLastName())  << "|"
                  << std::setw(10) << PhoneBook::formatColumn(this->contacts[i].getNickName())  << "|" << std::endl;
    }
    
}
/*
std::setw(10) è un manipolatore di stream (in <iomanip>) che imposta la larghezza minima del 
prossimo campo da stampare a 10 caratteri. Se il testo è più corto della larghezza → riempie con spazi
Se il testo è più lungo della larghezza → NON tronca
L’allineamento predefinito degli stream è a destra (std::right), ma è buona pratica impostarlo esplicitamente:
std::cout << std::right  << std::setw(10) << "ciao";  // "      ciao"
std::cout << std::left   << std::setw(10) << "ciao";  // "ciao      "
A differenza di setw, l’allineamento (std::left / std::right) è persistente finché non lo cambi.
#include <iomanip> per usare std::setw, std::left, std::right, std::setfill.

std::string, è la classe della STL (in <string>) che rappresenta una sequenza dinamica di caratteri. In pratica è una “stringa C++” comoda e sicura rispetto alle char* C.
Cosa fa esattamente
Gestione memoria automatica: alloca, rialloca e libera da sola. Tu non fai new/delete.
Mutabile: puoi aggiungere, togliere e cambiare caratteri.
Copia “profonda”: assegnare una stringa ad un’altra crea una copia dei dati (in C++98). Le due stringhe poi sono indipendenti.
Null-terminated per interoperabilità: espone c_str() per ottenere una const char* compatibile con funzioni C.
Metodi utili (C++98-friendly):
size() / length() → lunghezza.
empty() → è vuota?
operator[] / at() → accesso ai char (con/ senza check dei limiti).
append(), push_back(), +=, + → concatenazione.
substr(pos, len) → estrazione.
find(...), find_first_of/not_of(...), rfind(...) → ricerche.
compare(...) → confronto lessicografico.
erase(...), insert(...), replace(...), clear() → modifica del contenuto.
c_str() / data() → puntatore ai byte interni (read-only con c_str()).
Compatibile con stream: std::cin >> s o std::getline(std::cin, s); std::cout << s.
*/
