/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:58:41 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/30 20:17:06 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "Default FragTrap constructor" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) {
	std::cout << "Param FragTrap constructor" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src) {
	std::cout << "Default FragTrap copy constructor" << std::endl;
	*this = src;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}


//oh yeah mama, it doesn't matter

void	FragTrap::highFivesGuys() {
	std::string	str;
	
	std::cout << this->getName() << ", high five? (Y/N)" << std::endl;
	while (true) {
		if (std::getline(std::cin, str) && !str.empty()) {
			if (str[0] == 'Y' || str[0] == 'y') {
				std::cout << "Oh yeah mama, please continue" << std::endl;
				break ;
			}
			else if (str[0] == 'N' || str[0] == 'n') {
				std::cout << "It doesn't matter, continue" << std::endl;
				break ;
			}
			else
				std::cout << "Please type Y or N" << std::endl;
		}
		if (std::cin.eof()) {
			std::cerr << "End of input detected. Exiting." << std::endl;
			break ;
		}
	}
}
