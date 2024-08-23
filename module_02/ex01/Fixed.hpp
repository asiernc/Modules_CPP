/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 21:51:55 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/20 20:22:57 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>


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
		
		Fixed	&operator=(Fixed const &src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

};

std::ostream	&operator<<(std::ostream &out, Fixed const &src);

#endif
