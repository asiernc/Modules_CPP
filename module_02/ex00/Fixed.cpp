/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:38:48 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/10 15:38:05 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) {
	std::cout << "Default constructor called." << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Default destructor called." << std::endl;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called." << std::endl;
	*this = src;
	return ;
}

Fixed	&Fixed::operator=(Fixed const &src) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &src)
		// if i wish call a function in a const Fixed Obj (Fixed const &src), every function always be const
		this->_fixedPoint = src.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called." << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPoint = raw;
	return ;
}
