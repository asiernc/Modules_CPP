/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:38:48 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/17 21:44:59 by anovio-c         ###   ########.fr       */
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
		this->_fixedPoint = src.getRawBits();
	return (*this);
}

// es un método constante. Esto significa que el método no puede modificar ningún
// miembro de datos de la instancia de la clase en la que se llama, ni llamar a
// otros métodos no constantes de la misma clase.

// Al haber declarado arriba en el operador de asignacion el objeto como const,
// si quiero llamar a algun metodo a traves de el solo podra ser este const, si
// no lo es no podre llamarlo. Dara error. Esto se debe a que el compilador debe
// asegurarse de que no se modifique el estado del objeto

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called." << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPoint = raw;
	return ;
}
