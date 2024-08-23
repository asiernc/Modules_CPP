/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:07:06 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/23 15:18:31 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	
}

Point::Point(const Point &src) : _x(src._x), _y(src._y) {
	//std::cout << "Copy constructor called" << std::endl;
}


Point	&Point::operator=(const Point &src) {
	// los valores son constantes por lo que no son modificables una vez que
	// se asignan, por lo tanto, el operador de = deberia de ser anulado, o 
	// eliminado, 
	(void)src;
	return (*this);
}

Point::~Point() {
	
}

Fixed	Point::x(void) const {
	return (this->_x);
}

Fixed	Point::y(void) const {
	return (this->_y);
}

std::ostream	&operator <<(std::ostream &out, const Point &src) {
	out << "(" << src.x().toFloat() << "," << src.y().toFloat() << ")";
	return (out);
}
