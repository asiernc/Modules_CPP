/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:18:50 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/30 20:17:21 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : _gateMode(false) {
	std::cout << "ScavTrap default constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : _gateMode(false) {
	std::cout << "ScavTrap default constructor called." << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) {
	*this = src;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

bool	ScavTrap::getGuardGate() const {
	return (this->_gateMode);
}

void	ScavTrap::guardGate() {
	if (!this->getGuardGate()) {
		std::cout << "The guard gate of " << this->getName() << "'s cell is actived." << std::endl;
		this->_gateMode = true;
	}
	else {
		std::cout << "The guard gate of " << this->getName() << "'s cell is deactived." << std::endl;
		this->_gateMode = false;
	}
}
