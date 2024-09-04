/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:00:27 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/02 19:01:34 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Harl is here!" << std::endl;
}

Harl::~Harl() {
	std::cout << "Harl is gone!" << std::endl;
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

void	Harl::complain(std::string level) {
	int 		flag = 0;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*actions[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	for (int i = 0; i < 4; i++)
	{
		if (strcmp(level.c_str(), levels[i].c_str()) == 0)
			flag = 1;
		else
			continue ;
	}
	if (flag != 1)
		return ;
	switch (level[0])
	{
		case 'D':
			(this->*actions[0])();
			std::cout << std::endl;
			break;
		case 'I':
			(this->*actions[1])();
			std::cout << std::endl;
			break;
		case 'W':
			(this->*actions[2])();
			std::cout << std::endl;
			break;
		case 'E':
			(this->*actions[3])();
			std::cout << std::endl;
			break;
		default:
			std::cout << "Invalid level: " << level << std::endl;
			break ;
	}
}
