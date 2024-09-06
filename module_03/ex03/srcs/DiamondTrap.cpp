/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:27:48 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/06 19:10:39 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

// • Name, which is passed as parameter to a constructor
// • ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
// • Hit points (FragTrap)
// • Energy points (ScavTrap)
// • Attack damage (FragTrap)
// • attack() (Scavtrap)

DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("DefaultDiamondTrap") {
	std::cout << "DiamondTrap " << this->_name << " default constructor" << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name + "_scrav_name"), FragTrap(name + "_frag_name"),
	_name(name)	{
	std::cout << "DiamondTrap " << this->_name << " param constructor" << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
	: ClapTrap(src._name + "_clap_name"), ScavTrap(src._name + "_srav_name"), FragTrap(src._name + "_frag_name") {
	*this = src;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &src) {
	if (this != &src) {
		this->_name = src._name;
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->_name << " destructor" << std::endl;
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
