/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:21 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/07 16:04:03 by anovio-c         ###   ########.fr       */
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

void	Phonebook::show_help(void) {
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
			if (!this->_contacts[this->_index % MAX_CONTACTS].set_fname(str)) {
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
			if (!this->_contacts[this->_index % MAX_CONTACTS].set_lname(str)) {
				std::cout << "Error. Incorrect input. Contact not created." << std::endl;
				return ;
			}
			break ;
		}
	}
	while (!std::cin.eof()) {
		std::cout << "Enter " << name << "'s nickname: " << std::endl;
		if (std::getline(std::cin, str) && str != "") {
			if (!this->_contacts[this->_index % MAX_CONTACTS].set_nickname(str)) {
				std::cout << "Error. Incorrect input. Contact not created." << std::endl;
				return ;
			}
			break ;
		}
	}
	while (!std::cin.eof()) {
		std::cout << "Enter " << name << "'s phone number: " << std::endl;
		if (std::getline(std::cin, str) && str != "") {
			if (!this->_contacts[this->_index % MAX_CONTACTS].set_phoneNumber(str)) {
				std::cout << "Error. Incorrect input. Contact not created." << std::endl;
				return ;
			}
			break ;
		}
	}
	while (!std::cin.eof()) {
		std::cout << "Enter " << name << "'s darkest secret: " << std::endl;
		if (std::getline(std::cin, str) && str != "") {
			if (!this->_contacts[this->_index % MAX_CONTACTS].set_darkestSecret(str)) {
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
	std::cout << "First name: " << contact.get_fname() << std::endl;
	std::cout << "Last name: " << contact.get_lname() << std::endl;
	std::cout << "Nickname: " << contact.get_nickname() << std::endl;
	std::cout << "Phone number: " << contact.get_phoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.get_darkestSecret() << std::endl;
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
				&& this->_contacts[str[0] - 1 - '0'].get_fname().size())
				break ;
		}
		if (str == "")
			std::cout << "Invalid index." << std::endl;
	}
	if (!std::cin.eof()) {
		this->print_contact(this->_contacts[str[0] - 1 - '0']);
	}
}
