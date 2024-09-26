/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:52:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/04 21:23:01 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

AAnimal::AAnimal() : _type("Default") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << " AAnimal Parameterixed constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal	&AAnimal::operator=(const AAnimal &src) {
	std::cout << "AAnimal equal operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string	AAnimal::getType(void) const {
	return (this->_type);
}

void	AAnimal::makeSound(void) const {
	std::cout << "Default AAnimal sound" << std::endl;
}

