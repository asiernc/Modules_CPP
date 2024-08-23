/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:51:55 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/21 20:03:28 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

// Add these four public overloaded member functions to your class:
// • A static member function min that takes as parameters two references on
	// fixed-point numbers, and returns a reference to the smallest one.
// • A static member function min that takes as parameters two references
// to constant fixed-point numbers, and returns a reference to the smallest one.
// • A static member function max that takes as parameters two references
// on fixed-point numbers, and returns a reference to the greatest one.
// • A static member function max that takes as parameters two references
// to constant fixed-point numbers, and returns a reference to the greatest one.


class Fixed
{
	private:
		int					_fixedPoint;
		static const int	_fracBits = 8;

	public:
		Fixed();
		Fixed(int const intNum);
		Fixed(float const floatNum);
		Fixed(Fixed const &src);
		~Fixed();
		
		Fixed	&operator =(Fixed const &src);
		//The 6 comparison operators: >, <, >=, <=, == and !=.
		bool	operator >(Fixed const &src) const;
		bool	operator <(Fixed const &src) const;
		bool	operator >=(Fixed const &src) const;
		bool	operator <=(Fixed const &src) const;
		bool	operator ==(Fixed const &src) const;
		bool	operator !=(Fixed const &src) const;
		
		// arithmetic operator

		Fixed	operator +(Fixed const &src) const;
		Fixed	operator -(Fixed const &src) const;
		Fixed	operator *(Fixed const &src) const;
		Fixed	operator /(Fixed const &src) const;

		// increment and decrement pre and post

		Fixed	&operator ++(void);//pre
		Fixed	&operator --(void);//pre
		Fixed	operator ++(int); //post
		Fixed	operator --(int); //post

	// 	 • A static member function min that takes as parameters two references on
	// // fixed-point numbers, and returns a reference to the smallest one.

		static 			Fixed	&min(Fixed &a, Fixed &b);
		static const	Fixed	&min(const Fixed &a, const Fixed &b);
		static 			Fixed	&max(Fixed &a, Fixed &b);
		static const	Fixed	&max(const Fixed &a, const Fixed &b);
		int						getRawBits(void) const;
		void					setRawBits(int const raw);
		float					toFloat(void) const;
		int						toInt(void) const;

};

std::ostream	&operator<<(std::ostream &out, Fixed const &src);

#endif
