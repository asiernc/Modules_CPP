/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:47:49 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/02 11:53:40 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon), _name(name) {
	std::cout << "Human A: " << _name << " created and setted weapon: " << weapon.getType() << std::endl;
}

HumanA::~HumanA() {
	std::cout << "Human A: " << _name << " destroyed." << std::endl;
}

void	HumanA::attack(void) {
	std::cout << this->_name 
		<< " attacks with their "
		<< this->_weapon.getType()
		<< std::endl;
}
