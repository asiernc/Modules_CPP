/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:05:56 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/05 13:32:24 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void ) {
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed	c;
	
	std::cout << RED << a << RESET << std::endl;
	std::cout << RED << ++a << RESET << std::endl;
	std::cout << RED << a << RESET << std::endl;
	std::cout << RED << a++ << RESET << std::endl;
	std::cout << RED << a << RESET << std::endl;

	{
		std::cout << RED << "Value held of A: " << a << RESET << std::endl;
		std::cout << RED << "Value held of B: " << b << RESET << std::endl;
		std::cout << RED << "Max of A or B is: " << Fixed::max( a, b ).toFloat() << RESET << std::endl;

		std::cout << std::endl << std::endl;
		if (b > 8)
			std::cout << RED << b << " is higher than 8" << RESET << std::endl;

		c++;
		c++;
		--c;
		++c;
		std::cout << RED << "Value held of B: " << b << RESET << std::endl;
		std::cout << RED << "Value held of C: " << c << RESET << std::endl;
		c = c + Fixed(5.5f);
		std::cout << RED << "Value held of C + 5.5f: " << c << RESET << std::endl;
		if (b != c)
			std::cout << RED << b << " is not equal to " << c << RESET << std::endl;
		if (b >= c)
			std::cout << b << " is bigger than " << c << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

