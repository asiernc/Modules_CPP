/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:38:46 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/17 20:56:04 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string.h>

// A member function int getRawBits( void ) const; that returns the raw value of the fixed-point value.
// A member function void setRawBits( int const raw ); that sets the raw value of the fixed-point number

class Fixed
{
	private:
		int					_fixedPoint;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		// Se invoca cuando se crea un nuevo objeto Fixed como copia de un objeto
		//	existente.
		// Esto asegura que la copia sea una copia profunda, si es necesario, lo
		// 	que significa que cada objeto tiene sus propios datos independientes.
		Fixed(Fixed const &src);
		~Fixed();
		
		Fixed	&operator=(Fixed const &src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
