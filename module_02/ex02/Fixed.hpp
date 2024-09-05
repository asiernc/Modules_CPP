/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:51:55 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/05 13:46:43 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m" 

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
