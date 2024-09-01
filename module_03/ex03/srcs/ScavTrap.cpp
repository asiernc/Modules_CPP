/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:18:50 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/30 20:30:24 by anovio-c         ###   ########.fr       */
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

void	ScavTrap::sayHello() {
	std::cout << "Hello!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
	if (this->getHitPoints() == 0) {
		std::cout << "ScavTrap " <<  this->getName() << " is died, so, it cannot attack." << std::endl;
		return ;
	}
	if (this->getEnergyPoints() == 0) {
		std::cout << "ScavTrap " <<  this->getName() << " not have energy points, so, it cannot attack." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " <<  this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->_energyPoints--;
}
