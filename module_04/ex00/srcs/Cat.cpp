/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:25:39 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/01 21:47:46 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Default Cat constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &src) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat	&Cat::operator=(const Cat &src) {
	std::cout << "Cat equal operator called" << std::endl;
	_type = src.getType();
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

std::string	Cat::getType(void) const {
	return (this->_type);
}

void	Cat::makeSound() const {
	std::cout << "Meeeeoooooooow!" << std::endl;
}
