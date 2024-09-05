/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:55:03 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/05 13:26:53 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
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

Fixed	&Fixed::operator =(Fixed const &src) {
	std::cout << "Equal operator called" << std::endl;
	if (this != &src)
		this->_fixedPoint = src.getRawBits();
	return (*this); //devuelves puntero cuando quieres dvolver el obj modificado
}

// COMPARISON OPERATORS

bool	Fixed::operator >(Fixed const &src) const {
	return (this->_fixedPoint > src._fixedPoint);
}

bool	Fixed::operator <(Fixed const &src) const {
	return (this->_fixedPoint < src._fixedPoint);
}

bool	Fixed::operator >=(Fixed const &src) const {
	return (this->_fixedPoint >= src._fixedPoint);
}

bool	Fixed::operator <=(Fixed const &src) const {
	return (this->_fixedPoint <= src._fixedPoint);
}

bool	Fixed::operator ==(Fixed const &src) const {
	return (this->_fixedPoint == src._fixedPoint);
}

bool	Fixed::operator !=(Fixed const &src) const {
	return (this->_fixedPoint != src._fixedPoint);
}

// ARITHMETICS OPERATORS

Fixed	Fixed::operator +(Fixed const &src) const {
	Fixed	Result;

	Result.setRawBits(this->_fixedPoint + src._fixedPoint);
	return (Result);
}

Fixed	Fixed::operator -(Fixed const &src) const {
	Fixed	Result;

	Result.setRawBits(this->_fixedPoint - src._fixedPoint);
	return (Result);
}

Fixed	Fixed::operator *(Fixed const &src) const {
	Fixed	Result;

	Result.setRawBits((this->_fixedPoint * src._fixedPoint) >> this->_fracBits);
	return (Result);
}

Fixed	Fixed::operator /(Fixed const &src) const {
	Fixed	Result;

	Result.setRawBits((this->_fixedPoint << this->_fracBits) / src._fixedPoint);
	return (Result);
}

// INCREMENT / DECREMENT OPERATORS

Fixed	&Fixed::operator ++() {
	this->_fixedPoint++;
	return (*this);
}

Fixed	&Fixed::operator--() {
	this->_fixedPoint--;
	return (*this);
}

Fixed	Fixed::operator ++(int) {
	Fixed	tmp(*this);

	this->_fixedPoint++;
	return (tmp);
}

Fixed	Fixed::operator --(int) {
	Fixed	tmp(*this);

	this->_fixedPoint--;
	return (tmp);
}

// If it is not done with reference, a copy of the object will be created and
// it will be returned, losing the thread of the class, on the other hand, if
// the reference is returned what we are doing is returning the object we want,
// and if we call it
// ex Fixed &c = min(a, b), c shall have the child's reference. not a copy.

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a < b)
		return (b);
	return (a);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	if (a < b)
		return (b);
	return (a);
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
