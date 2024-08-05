/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:55 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/05 19:28:56 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhonebookUtils.hpp"

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

int	display_contacts(Contact contact[8]) {
	std::string	str;
	char		i;
	int			counter;

	i = '0';
	counter = 0;
	while (++i <= '8') {
		if (contact[i - 1 - '0'].get_fname().size()) {
			if (i == '1')
				display_header();
			str = i;
			str = parse_line(str);
			std::cout << "|" << str;
			str = parse_line(contact[i - 1 - '0'].get_fname());
			std::cout << "|" << str;
			str = parse_line(contact[i - 1 - '0'].get_lname());
			std::cout << "|" << str;
			str = parse_line(contact[i - 1 - '0'].get_nickname());
			std::cout << "|" << str << "|" << std::endl;
			counter++;
		}
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	return (counter);
}
