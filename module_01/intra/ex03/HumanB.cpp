/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:47:49 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/02 11:49:39 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name) : _name(name) {
	std::cout << "Human B: " << _name << " is created." << std::endl;
}

HumanB::~HumanB() {
	std::cout << "Human B: " << _name << " is destroyed." << std::endl;	
}

void	HumanB::attack(void) {
	if (_weapon) {
		std::cout << this->_name 
			<< " attacks with their "
			<< this->_weapon->getType()
			<< std::endl;
	} else {
		std::cout <<
			_name << " has no weapon to attack with!"
			<< std::endl;
	}
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
	std::cout << _name << " setted weapon: " << weapon.getType() << std::endl;
}
