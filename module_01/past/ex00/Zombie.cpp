/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 20:33:39 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/10 12:34:52 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Destructor called. Zombie "
		<< this->_name << " was killed."
		<< std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}

void	Zombie::announce(void) {
	std::cout << this->_name 
		<< ": BraiiiiiiinnnzzzZ..."
		<< std::endl;
}
