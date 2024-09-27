/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:06:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/26 22:09:30 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
	
}
ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	*this = src;
}
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src) {
	(void)src;
	return (*this);
}
ScalarConverter::~ScalarConverter(void) {
	
}

bool	ScalarConverter::isChar(std::string &ref) {
	return (ref.length() == 1
		|| (ref.length() == 3 && (ref.front() == '\'' && ref.back() == '\'')));
}

bool	ScalarConverter::isInt(std::string &str) {
	if (str.empty())
		return (false);
	for (int i = 0; i < str.length(); i++) {
		if (i == 0) {
			if (str[0] != '+' || str[0] != '-'
				|| (str[0] < '0' || str[0] > '9'))
				return (false) ;
		}
		if ((str[0] >= '0' && str[0] <= '9'))
			continue;
		else
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(std::string &str) {
	if (str.find('.') != std::string::npos && str[str.length() - 1] == 'f')
		return (true);
}

bool	ScalarConverter::isDouble(std::string &str) {
	if (str.find('.') != std::string::npos && str[str.length() - 1] != 'f')
		return (true);
}

bool	ScalarConverter::isSpecialLiteral(std::string &str) {
	if (str == "nan" || str == "nanf" || str == "+inf" ||
		str == "-inf" || str == "+inff" || str == "-inff")
		return (true);
}

void	ScalarConvert::showChar(std::string num) {
	char c = num[0];

		
}

void	ScalarConverter::convert(std::string num) {
	if (isChar(num))
		showChar(num);
	else if (isInt(num))
		showInt(num);
	else if (isFloat(num))
		showFloat(num);
	else if (isDouble(num))
		showDouble(num);
	else if (isSpecialLiteral(num))
		showSpecialLiteral(num);
}