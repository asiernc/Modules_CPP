/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:55 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/13 21:22:37 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhonebookUtils.hpp"

bool	onlySpaces(std::string str) {
	for (int i = 0; str[i]; i++) {
		if (!std::isspace(str[i]))
			return (false);
	};
	return (true);
}

bool	checkPhoneNumber(std::string str) {
	for (int i = 0; i < str[i]; i++)
	{
		if (i == '+' && i != 0)
			return (false);
		if (!std::isdigit(str[i]) && str[i] != '+')
			return (false);
	}
	return (true);
}

std::string		parse_line(std::string str) {
	if (str.size() > MAX_CHARACTERS) {
		str.resize(MAX_CHARACTERS);
		str[MAX_CHARACTERS - 1] = '.';
	}
	if (str.size() < MAX_CHARACTERS)
		str.insert(0, MAX_CHARACTERS - str.size(), ' ');
	return (str);
}

void	display_header(void) {
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

int	display_contacts(Contact contact[MAX_CONTACTS]) {
	std::string	str;
	char		i;
	int			counter;

	i = '0';
	counter = 0;
	while (++i <= '8') {
		if (contact[i - 1 - '0'].getFirstName().size()) {
			if (i == '1')
				display_header();
			str = i;
			str = parse_line(str);
			std::cout << "|" << str;
			str = parse_line(contact[i - 1 - '0'].getFirstName());
			std::cout << "|" << str;
			str = parse_line(contact[i - 1 - '0'].getLastName());
			std::cout << "|" << str;
			str = parse_line(contact[i - 1 - '0'].getNickname());
			std::cout << "|" << str << "|" << std::endl;
			counter++;
		}
	}
	if (counter != 0)
		std::cout << "|-------------------------------------------|" << std::endl;
	return (counter);
}
