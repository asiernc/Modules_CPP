/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:03:25 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/07 18:35:25 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "whatever.hpp"

int main( void ) {
	float a = 2.5;
	float b = 10.3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "Swapping..."<< std::endl;
	::swap( a, b );
	std::cout << "a = " << a << " -- REF --> " << &a << std::endl;
	std::cout << "b = " << b << " -- REF --> " << &b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "MIN REFERENCE returned = " << &::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "MAX REFERENCE returned = " << &::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "Swapping..."<< std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
