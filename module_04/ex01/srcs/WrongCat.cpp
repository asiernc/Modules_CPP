/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:25:39 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/02 10:01:50 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal() {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat	&WrongCat::operator=(const WrongCat &src) {
	std::cout << "WrongCat equal operator called" << std::endl;
	this->_type = src.getType();
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

std::string	WrongCat::getType(void) const {
	return (this->_type);
}

void	WrongCat::makeSound() const {
	std::cout << "Muuuuuuuuuuuuuuu!" << std::endl;
}
