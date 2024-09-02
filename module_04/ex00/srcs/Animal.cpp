/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:52:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/01 21:44:10 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() : _type("Default") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << " Animal Parameterixed constructor called" << std::endl;
}

Animal::Animal(const Animal &src) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal	&Animal::operator=(const Animal &src) {
	std::cout << "Animal equal operator called" << std::endl;
	_type = src.getType();
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType(void) const {
	return (this->_type);
}

void	Animal::makeSound(void) const {
	std::cout << "Default Animal sound" << std::endl;
}
