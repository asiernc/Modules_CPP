/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:04:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/22 20:15:56 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP


# include "Fixed.hpp"
// Let’s start by creating the class Point in Orthodox Canonical Form that represents a 2D point:
// • Private members:
// ◦ A Fixed const attribute x. ◦ A Fixed const attribute y. ◦ Anything else useful.
// • Public members:
// ◦ A default constructor that initializes x and y to 0.
// ◦ A constructor that takes as parameters two constant floating-point numbers. It initializes x and y with those parameters.
// ◦ A copy constructor.
// ◦ A copy assignment operator overload.
// ◦ A destructor.
// ◦ Anything else useful.

class Point
{
private:
	const Fixed	_x;
	const Fixed _y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &src);
	~Point();

	Point	&operator=(const Point &src);
	Fixed	x(void) const;
	Fixed	y(void) const;
};

std::ostream	&operator <<(std::ostream &out, const Point &src);

#endif
