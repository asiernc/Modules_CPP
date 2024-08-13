/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:08 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/12 14:57:00 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){
}

Contact::~Contact(void){
}

std::string	Contact::getFname(void) {
	return (this->fname);
}

std::string Contact::getLname(void) {
	return (this->lname);
}

std::string Contact::getNickname(void) {
	return (this->nickname);
}

std::string Contact::getPhoneNumber(void) {
	return (this->phonenum);
}

std::string Contact::getDarkestSecret(void) {
	return (this->secret);
}

bool Contact::onlySpaces(std::string str) {
	for (int i = 0; str[i]; i++) {
		if (!std::isspace(str[i]))
			return (false);
	};
	return (true);
}

bool	Contact::setFname(std::string str){
	if (onlySpaces(str))
		return (false);
	this->fname = str;
	return (true);
}

bool	Contact::setLname(std::string str) {
	if (onlySpaces(str))
		return (false);
	this->lname = str;
	return (true);
}

bool	Contact::setNickname(std::string str) {
	if (onlySpaces(str))
		return (false);
	this->nickname = str;
	return (true);
}

bool	Contact::setPhoneNumber(std::string str) {
	for (int i = 0; i < str[i]; i++)
	{
		if (i == '+' && i != 0)
			return (false);
		if (!std::isdigit(str[i]) && str[i] != '+')
			return (false);
	}
	this->phonenum = str;
	return (true);
}

bool	Contact::setDarkestSecret(std::string str) {
	if (onlySpaces(str))
		return (false);
	this->secret = str;
	return (true);
}

