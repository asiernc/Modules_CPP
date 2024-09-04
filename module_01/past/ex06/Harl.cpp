/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:00:27 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/15 21:46:59 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	
}

Harl::~Harl() {
	
}

void	Harl::_debug() {
	std::cout << GREEN << "I'm making magic with bits!" << RESET << std::endl;
}

void	Harl::_info() {
	std::cout << BLUE << "There are no surprises here, everything is predictable." << RESET
		<< std::endl;
}

void	Harl::_warning() {
	std::cout << YELLOW << "Watch out! This could blow up at any moment." << RESET
		<< std::endl;
}

void	Harl::_error() {
	std::cout << BACK_RED << "Houston, we have a problem!" << RESET << std::endl;
}

bool	Harl::complain(std::string level) {
	void	(Harl::*actions[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	switch (level[0])
	{
		case 'D':
			(this->*actions[0])();
		case 'I':
			(this->*actions[1])();
		case 'W':
			(this->*actions[2])();
		case 'E':
			(this->*actions[3])();
			std::cout << std::endl;
			return (true);
	}
	return (false);
}
