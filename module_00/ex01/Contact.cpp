/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:08 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/05 19:28:09 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){
}

Contact::~Contact(void){
}

std::string	Contact::get_fname(void) {
	return (this->fname);
}

std::string Contact::get_lname(void) {
	return (this->lname);
}

std::string Contact::get_nickname(void) {
	return (this->nickname);
}

std::string Contact::get_phoneNumber(void) {
	return (this->phonenum);
}

std::string Contact::get_darkestSecret(void) {
	return (this->secret);
}

bool Contact::only_spaces(std::string str) {
	for (int i = 0; str[i]; i++) {
		if (!std::isspace(str[i]))
			return (false);
	};
	return (true);
}

bool	Contact::set_fname(std::string str){
	if (only_spaces(str))
		return (false);
	this->fname = str;
	return (true);
}

bool	Contact::set_lname(std::string str) {
	if (only_spaces(str))
		return (false);
	this->lname = str;
	return (true);
}

bool	Contact::set_nickname(std::string str) {
	if (only_spaces(str))
		return (false);
	this->nickname = str;
	return (true);
}

bool	Contact::set_phoneNumber(std::string str) {
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

bool	Contact::set_darkestSecret(std::string str) {
	if (only_spaces(str))
		return (false);
	this->secret = str;
	return (true);
}

