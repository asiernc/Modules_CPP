/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:19:12 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/02 12:31:15 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
	//std::cout << "Default ScalarConverter constructor" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	//std::cout << "ScalarConverter copy assignment" << std::endl;
	*this = src;
}
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src) {
	//std::cout << "ScalarConverter equal operator" << std::endl;
	(void)src;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {
	//std::cout << "Default ScalarConverter destructor" << std::endl;
}
