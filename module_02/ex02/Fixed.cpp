/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:55:03 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/22 18:45:11 by anovio-c         ###   ########.fr       */
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
	// Se incrementa con normalidad y se devuelve la referencia de este objeto 
	// modificado.
	this->_fixedPoint++;
	return (*this);
}

Fixed	&Fixed::operator--() {
	this->_fixedPoint--;
	return (*this);
}

Fixed	Fixed::operator ++(int) {
	// se crea un objeto temporal, que sera una copia del actual. este sera el
	// se devuelva, para que sea evaluado antes de ser modificado.
	Fixed	tmp(*this);

	this->_fixedPoint++;
	return (tmp);
}

Fixed	Fixed::operator --(int) {
	Fixed	tmp(*this);

	this->_fixedPoint--;
	return (tmp);
}

// se trabaja con referencias para no sobrecargar la memoria, si no se hace con
// referencia se va a crear una copia del objeto y esta sera devuelta,
// perdiendo el hilo de la clase, en cambio, si se devuelve la referencia lo 
// que estamos haciendo es devolviendo el objeto que queremos, y si lo llamamos
// ex Fixed &c = min(a, b), c tendra la referenia del menor. y no una copia.
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
