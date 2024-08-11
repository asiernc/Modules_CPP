/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:17:32 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/10 21:21:05 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	std::cout << "Constructor Weapon called" << std::endl;
	this->setType(type);
}

Weapon::~Weapon() {
	std::cout << "Destructor Weapon called" << std::endl;
}

const std::string	&Weapon::getType(void) {
	return (this->_type);
}

void	Weapon::setType(std::string type) {
	this->_type = type;
}
