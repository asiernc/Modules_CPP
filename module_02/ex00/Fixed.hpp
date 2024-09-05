/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:38:46 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/05 10:49:44 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string.h>

class Fixed
{
	private:
		int					_fixedPoint;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		// This ensures that the copy is a deep copy, if necessary, meaning
		// that each object has its own independent data.
		Fixed(Fixed const &src);
		Fixed	&operator=(Fixed const &src);
		~Fixed();
		
		int		getRawBits(void) const ;
		void	setRawBits(int const raw);
};

#endif
