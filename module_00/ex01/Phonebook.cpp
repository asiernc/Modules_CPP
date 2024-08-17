/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:21 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/17 16:21:56 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "PhonebookUtils.hpp"

Phonebook::Phonebook(void){
	this->_index = 0;
	std::cout << \
		"Welcome to DustyDiary! Phonebook created with 8 empty contacts." \
		<< std::endl << std::endl;
	
	this->showHelp();
	std::cout << std::endl;
}

Phonebook::~Phonebook(void){
	std::cout << "See you soon!" << std::endl;
}

void	Phonebook::showHelp(void) {
	std::cout << "- Use ADD	to add new contact" << std::endl;
	std::cout << "- Use SEARCH	to search in Phonebook" << std::endl;
	std::cout << "- Use EXIT	to close and delete Phonebook" << std::endl;
}

// si pasamos Contact Shallow estás pasando el contacto Shallow por valor, lo que
// significa que se hace una copia del objeto y los cambios realizados en él no
// afectarán al objeto original. Para modificar el objeto real, debes pasar el
// contacto por referencia.

bool	Phonebook::checkFirstName(Contact &Shallow) {
    std::string str;
    
    while (!std::cin.eof()) {
        std::cout << "Enter a first name (or type 'cancel' to abort): " << std::endl;
        if (std::getline(std::cin, str) && str != "") {
            if (str == "cancel") {
                std::cout << "Operation cancelled." << std::endl;
                return (false);
            }
            if (!onlySpaces(str)) {
                Shallow.setFirstName(str);
                return (true);
            } else
                std::cout << "Error. Incorrect input. Repeat." << std::endl;
        }
    }
	return (false);
}

bool		Phonebook::checkLastName(Contact &Shallow) {
	std::string	str;
	
	str = "";
	while (!std::cin.eof()) {
		std::cout << "Enter " << Shallow.getFirstName() << "'s last name (or type 'cancel' to abort): "<< std::endl;
		if (std::getline(std::cin, str) && str != "") {
			if (str == "cancel") {
                std::cout << "Operation cancelled." << std::endl;
                return (false);
            }
			if (!onlySpaces(str)) {
				Shallow.setLastName(str);
				return (true);
			}
			else
				std::cout << "Error. Incorrect input. Repeat." << std::endl;
		}
    }
	return (false);
}

bool		Phonebook::checkNickName(Contact &Shallow) {
	std::string	str;
	
	str = "";
	while (!std::cin.eof()) {
		std::cout << "Enter " << Shallow.getFirstName() << "'s nickname (or type 'cancel' to abort): "<< std::endl;
		if (std::getline(std::cin, str) && str != "") {
			if (str == "cancel") {
                std::cout << "Operation cancelled." << std::endl;
                return (false);
            }
			if (!onlySpaces(str)) {
				Shallow.setNickname(str);
				return (true);
			}
			else
				std::cout << "Error. Incorrect input. Repeat." << std::endl;
		}
    }
	return (false);
}
bool		Phonebook::checkPhoneNum(Contact &Shallow) {
	std::string	str;
	
	str = "";
	while (!std::cin.eof()) {
		std::cout << "Enter " << Shallow.getFirstName() << "'s phone number (or type 'cancel' to abort): "<< std::endl;
		if (std::getline(std::cin, str) && str != "") {
			if (str == "cancel") {
                std::cout << "Operation cancelled." << std::endl;
                return (false);
            }
			if (!onlySpaces(str) && checkPhoneNumber(str)) {
				Shallow.setPhoneNumber(str);
				return (true);
			}
			else
				std::cout << "Error. Incorrect input. Repeat." << std::endl;
		}
    }
	return (false);
}

bool		Phonebook::checkDarkestSecret(Contact &Shallow) {
	std::string	str;
	
	str = "";
	while (!std::cin.eof()) {
		std::cout << "Enter " << Shallow.getFirstName() << "'s darkest secret (or type 'cancel' to abort): "<< std::endl;
			if (std::getline(std::cin, str) && str != "") {
				if (str == "cancel") {
					std::cout << "Operation cancelled." << std::endl;
					return (false);
				}
				if (!onlySpaces(str)) {
					Shallow.setDarkestSecret(str);
					return (true);
				}
				else
					std::cout << "Error. Incorrect input. Repeat." << std::endl;
			}
	}
	return (false);
}

bool	Phonebook::checkContact(Contact Shallow) {
	if (!Shallow.getFirstName().size())
		return (false);
	if (!Shallow.getLastName().size())
		return (false);
	if (!Shallow.getNickname().size())
		return (false);
	if (!Shallow.getPhoneNumber().size())
		return (false);
	if (!Shallow.getDarkestSecret().size())
		return (false);
	return (true);
}

void	Phonebook::add(void) {
	Contact Shallow;

	if (!checkFirstName(Shallow)) return ;
	if (!checkLastName(Shallow)) return ;
	if (!checkNickName(Shallow)) return ;
	if (!checkPhoneNum(Shallow)) return ;
	if (!checkDarkestSecret(Shallow)) return ;
	if (checkContact(Shallow)) {
		this->_contacts[this->_index % MAX_CONTACTS] = Shallow;
		std::cout << Shallow.getFirstName() << " successfully added to DustyDiary. Index: ["
			<< this->_index % MAX_CONTACTS + 1 << "/8]" << std::endl;
		this->_index++;
	}
	else
		std::cout << "Error creating new contact." << std::endl;
}

void	Phonebook::print_contact(Contact contact) {
	std::cout << "Requesting contact information..." << std::endl;
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

void	Phonebook::search(void) {
	std::string	str;

	if (!display_contacts(this->_contacts)) {
		std::cout << "Phonebook is empty!" << std::endl;
		return ;
	}
	while (!std::cin.eof()) {
		std::cout << "Enter a index to search (0 to come back): " << std::endl;
		if (std::getline(std::cin, str) && str != "") {
			if (str[0] == '0')
				return ;
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8') {
					std::cout << "Searching contact information..." << std::endl;
					break ;
				}
			if (str[0] < '1' || str[0] > '8')
				std::cout << "Invalid index." << std::endl;
		}
		if (str == "")
			std::cout << "Invalid index." << std::endl;
	}
	if (!std::cin.eof() && this->_contacts[str[0] - 1 - '0'].getFirstName().size())
		this->print_contact(this->_contacts[str[0] - 1 - '0']);
	else
		std::cout << "Contact number " << str[0] - '0' << " doesn't exists yet." << std::endl;
}
