/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:21 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/12 15:04:41 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "PhonebookUtils.hpp"

Phonebook::Phonebook(void){
	this->_index = 0;
	std::cout << \
		"Welcome to DustyDiary! Phonebook created with 8 empty contacts." \
		<< std::endl;
	std::cout << "Use -h to see commands." << std::endl;
}

Phonebook::~Phonebook(void){
	std::cout << "See you soon!" << std::endl;
}

void	Phonebook::showHelp(void) {
	std::cout << "Use ADD		to add new contact" << std::endl;
	std::cout << "Use SEARCH	to search in Phonebook" << std::endl;
	std::cout << "Use EXIT	to close and delete Phonebook" << std::endl;
}

void	Phonebook::add(void) {
	std::string	str;
	std::string name;

	std::cout << "Creating new contact..." << std::endl;
	while (!std::cin.eof()) {
		std::cout << "Enter a first name: " << std::endl;
		if (std::getline(std::cin, str) && str != "") {
			if (!this->_contacts[this->_index % MAX_CONTACTS].setFname(str)) {
				std::cout << "Error. Incorrect input. Contact not created. " << std::endl;
				return ;
			}
			name = str;
			break ;
		}
	}
	while (!std::cin.eof()) {
		std::cout << "Enter " << name << "'s last name: " << std::endl;
		if (std::getline(std::cin, str) && str != "") {
			if (!this->_contacts[this->_index % MAX_CONTACTS].setLname(str)) {
				std::cout << "Error. Incorrect input. Contact not created." << std::endl;
				return ;
			}
			break ;
		}
	}
	while (!std::cin.eof()) {
		std::cout << "Enter " << name << "'s nickname: " << std::endl;
		if (std::getline(std::cin, str) && str != "") {
			if (!this->_contacts[this->_index % MAX_CONTACTS].setNickname(str)) {
				std::cout << "Error. Incorrect input. Contact not created." << std::endl;
				return ;
			}
			break ;
		}
	}
	while (!std::cin.eof()) {
		std::cout << "Enter " << name << "'s phone number: " << std::endl;
		if (std::getline(std::cin, str) && str != "") {
			if (!this->_contacts[this->_index % MAX_CONTACTS].setPhoneNumber(str)) {
				std::cout << "Error. Incorrect input. Contact not created." << std::endl;
				return ;
			}
			break ;
		}
	}
	while (!std::cin.eof()) {
		std::cout << "Enter " << name << "'s darkest secret: " << std::endl;
		if (std::getline(std::cin, str) && str != "") {
			if (!this->_contacts[this->_index % MAX_CONTACTS].setDarkestSecret(str)) {
				std::cout << "Error. Incorrect input. Contact not created." << std::endl;
				return ;
			}
			break ;
		}
		std::cout << name << " succesfully added to DustyDiary. Is the index: [" <<
			this->_index % MAX_CONTACTS + 1 << "/8]" << std::endl;
		}
	this->_index++;
	return ;
}

void	Phonebook::print_contact(Contact contact) {
	std::cout << "Requesting contact information..." << std::endl;
	std::cout << "First name: " << contact.getFname() << std::endl;
	std::cout << "Last name: " << contact.getLname() << std::endl;
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
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8'
				&& this->_contacts[str[0] - 1 - '0'].getFname().size())
				break ;
		}
		if (str == "")
			std::cout << "Invalid index." << std::endl;
	}
	if (!std::cin.eof()) {
		this->print_contact(this->_contacts[str[0] - 1 - '0']);
	}
}
