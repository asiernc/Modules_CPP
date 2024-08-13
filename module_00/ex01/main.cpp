/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:28:49 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/12 15:04:41 by anovio-c         ###   ########.fr       */
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
			phonebook.showHelp();
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
