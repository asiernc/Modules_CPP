/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:55:03 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/20 20:17:36 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

// copy constructor
Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int intNum) {
	std::cout << "Intenger constructor called" << std::endl;
	this->_fixedPoint = intNum << this->_fracBits;
}

Fixed::Fixed(const float floatNum) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(floatNum * (1 << this->_fracBits));
}

float	Fixed::toFloat(void) const {
	return ((float)this->_fixedPoint / (1 << this->_fracBits));
}
int		Fixed::toInt(void) const {
	return ((int)this->_fixedPoint >> this->_fracBits);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &src) {
	std::cout << "Equal operator called" << std::endl;
	if (this != &src)
		this->_fixedPoint = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPoint = raw;
	return ;
}

std::ostream	&operator<<(std::ostream &out, Fixed const &src) {
	out << src.toFloat();
	return (out);
}
