/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:08 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/13 21:12:42 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){
}

Contact::~Contact(void){
}

std::string	Contact::getFirstName(void) {
	return (this->_firstName);
}

std::string Contact::getLastName(void) {
	return (this->_lastName);
}

std::string Contact::getNickname(void) {
	return (this->_nickname);
}

std::string Contact::getPhoneNumber(void) {
	return (this->_phonenum);
}

std::string Contact::getDarkestSecret(void) {
	return (this->_secret);
}

void	Contact::setFirstName(std::string str){
	this->_firstName = str;
}

void	Contact::setLastName(std::string str) {
	this->_lastName = str;
}

void	Contact::setNickname(std::string str) {
	this->_nickname = str;
}

bool	Contact::setPhoneNumber(std::string str) {
	for (int i = 0; i < str[i]; i++)
	{
		if (i == '+' && i != 0)
			return (false);
		if (!std::isdigit(str[i]) && str[i] != '+')
			return (false);
	}
	this->_phonenum = str;
	return (true);
}

void	Contact::setDarkestSecret(std::string str) {
	this->_secret = str;
}

