/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:00:24 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/15 21:09:48 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
	Harl harl;
	std::string	str;

	while (!std::cin.eof()) {
		std::cout << "The levels of Harl 2.0 are DEBUG, INFO, WARNING, ERROR." << std::endl;
		std::cout << "Enter a level (control + d to exit): " << std::endl;
		std::getline(std::cin, str);
		if (str.size())
			harl.complain(str);
	}
	return (0);
}
