/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:32:11 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/02 10:15:14 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"


Dog::Dog() : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	//this->_type = "Dog";
}

Dog::Dog(const Dog &src) : Animal("Dog") {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog	&Dog::operator=(const Dog &src) {
	std::cout << "Dog equal operator called" << std::endl;
	if (this != &src) {
		_type = src._type;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

std::string	Dog::getType(void) {
	return (this->_type);
}

void	Dog::makeSound() const{
	std::cout << "Woof Woof!" << std::endl;
}
