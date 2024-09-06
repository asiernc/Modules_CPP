/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:03:48 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/05 19:55:41 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"


ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)  {
	std::cout << "Default ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Parameterixed constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	std::cout << "ClapTrap Copy constructor for " << src.getName() <<"called." << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called." << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src) {
	std::cout << "ClapTrap Equal operator for constructor " << src.getName() << " called." << std::endl;
	// is better with getters o directly the value of the variable ex _name
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

std::string	ClapTrap::getName() const {
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints() const {
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const {
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage() const {
	return (this->_attackDamage);
}

void ClapTrap::attack(const std::string& target) {
	if (this->getHitPoints() == 0) {
		std::cout << "ClapTrap " <<  this->getName() << " is died, so, it cannot attack." << std::endl;
		return ;
	}
	if (this->getEnergyPoints() == 0) {
		std::cout << "ClapTrap " <<  this->getName() << " not have energy points, so, it cannot attack." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " <<  this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->_energyPoints--;
}
void ClapTrap::takeDamage(unsigned int amount) {
	if (this->getHitPoints() == 0) {
		std::cout << "ClapTrap " <<  this->getName() << " is died." << std::endl;
		return ;
	}
	if (this->getHitPoints() >= amount) {
		std::cout << "ClapTrap " <<  this->getName() << " suffered the " << amount << "-point attack." << std::endl;
		this->_hitPoints -= amount;
	}
	else
		std::cout << "ClapTrap " <<  this->getName() << " not have " << amount << " points to attack." << std::endl;
	if (this->getHitPoints() < 0)
		this->_hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->getHitPoints() == 0) {
		std::cout << "ClapTrap " <<  this->getName() << " is died, so, it cannot be repaired." << std::endl;
		return ;
	}
	if (this->getEnergyPoints() == 0) {
		std::cout << "ClapTrap " <<  this->getName() << " not have energy points to be repaired." << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	std::cout << "ClapTrap " <<  this->getName() << " be repaired with " << amount << " points." << std::endl;
	this->_energyPoints--;
}
