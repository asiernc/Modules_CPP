/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:07:06 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/05 13:47:33 by anovio-c         ###   ########.fr       */
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
	(void)src;
	return (*this);
}

Point::~Point() {
	//std::cout << "Default destructor called" << std::endl;
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
