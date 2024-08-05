/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:49 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/05 19:28:50 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
	Phonebook	phonebook;
	std::string	str;

	while (str != "EXIT") {
		std::cout << "Enter a command >" << std::endl;
		std::getline(std::cin, str);
		if (str == "-h")
			phonebook.show_help();
		if (str == "ADD")
			phonebook.add();
		else if (str == "SEARCH")
			phonebook.search();
		if (std::cin.eof()) {
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
