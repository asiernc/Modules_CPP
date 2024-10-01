/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:06:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/27 20:09:30 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Converter.hpp"

Converter::Converter(void) : ScalarConverter() {
	std::cout << "Default Converter constructor" << std::endl;
	this->_input = "";
	this->_inputType = 0;
	this->_specialLiteral = 0;
	this->_char = 0;
	this->_int = 0;
	this->_float = 0;
	this->_double = 0;
}

Converter::Converter(std::string &input) : ScalarConverter() {
	std::cout << "Converter param constructor" << std::endl;
	this->_input = input;
	this->_inputType = 0;
	this->_specialLiteral = 0;
	this->_char = 0;
	this->_int = 0;
	this->_float = 0;
	this->_double = 0;
}

Converter::Converter(const Converter &src) : ScalarConverter() {
	std::cout << "Converter copy constructor" << std::endl;
	this->_input = src.getInput();
	this->_inputType = src.getInputType();
	this->_specialLiteral = src.getSpecialLiteral();
	this->_char = src.getChar();
	this->_int = src.getInt();
	this->_float = src.getFloat();
	this->_double = src.getDouble();
}
Converter	&Converter::operator=(const Converter &src) {
	std::cout << "Converter equal operator" << std::endl;
	this->_input = src.getInput();
	this->_char = src.getChar();
	this->_int = src.getInt();
	this->_float = src.getFloat();
	this->_double = src.getDouble();
	this->_specialLiteral = src.getSpecialLiteral();
	return (*this);
}
Converter::~Converter(void) {
	std::cout << "Converter destructor" << std::endl;
}

std::string Converter::getInput(void) const { return this->_input; }
int			Converter::getInputType(void) const { return this->_inputType; }
char		Converter::getChar(void) const { return this->_char; }
int			Converter::getInt(void) const { return this->_int; }
float		Converter::getFloat(void) const { return this->_float; }
double		Converter::getDouble(void) const { return this->_double; }
int			Converter::getSpecialLiteral(void) const { return this->_specialLiteral; }


bool	Converter::isChar(std::string &ref) {
	return (ref.length() == 1 ||
		(ref.length() == 3 && (ref.front() == '\'' && ref.back() == '\'')));
}

bool	Converter::isInt(std::string &str) {
	if (str.empty())
		return (false);

	size_t	i = 0;
	if (str[0] == '+' || str[0] == '-') {
		if (str.length() == 1)
			return (false);
		i = 1;
	}
	for (; i < str.length(); i++) {
		if (str[i] < '0' || str[i] >'9')
			return (false);
	}
	return (true);
}

bool	Converter::isFloat(std::string &str) {
	if (str.find('.') != std::string::npos && str[str.length() - 1] == 'f')
		return (true);
	return (false);
}

bool	Converter::isDouble(std::string &str) {
	if (str.find('.') != std::string::npos && str[str.length() - 1] != 'f')
		return (true);
	return (false);
}

void	Converter::checkInput(std::string &str) {
	if (!str.compare("nan") || !str.compare("nanf")) {
		this->_inputType = SPECIAL;
		this->_specialLiteral = NaN;
	}
	else if (!str.compare("+inf") || !str.compare("-inf") || !str.compare("+inff") || !str.compare("-inff")) {
        this->_inputType = SPECIAL;
		// to do MEJORAR y !!
		// - Hacer un display para cada uno de los inf, entenderlo mejor si
		// he de mostrar uno para cada uno o no, o hacer solo dos y compartidos.
        if (str[0] == '+')
            this->_specialLiteral = (str.back() == 'f') ? PLUS_INFF : PLUS_INF;
        else if (str[0] == '-')
            this->_specialLiteral = (str.back() == 'f') ? MINUS_INFF : MINUS_INF;
	}
	else {
		if (isChar(str)) {
			this->_inputType = CHAR;
			return ;
		}
		else if (isInt(str)) {
			this->_inputType = INT;
			return ;
		}
		else if (isFloat(str)) {
			this->_inputType = FLOAT;
			return ;
		}
		else if (isDouble(str)) {
			this->_inputType = DOUBLE;
			return ;
		}
	}
	if (!this->_inputType && !this->_specialLiteral)
		throw notValidInput();
}

void	Converter::displayPrompt(void) {
	if (this->_char == NON_DISPL || this->_inputType == SPECIAL)
		std::cout << "Char: " << "Non displayable" << std::endl;
	else
		std::cout << "Char: " << this->_char << std::endl;
	std::cout << "Int: " << this->_int << std::endl;
	std::cout << "Float: " << this->_float;
	if (this->_float == static_cast<int>(this->_float))
		std::cout << ".0f" << std::endl;
	else
		std::cout << 'f' << std::endl;
	std::cout << "Double: " << this->_double;
	if (this->_double == static_cast<int>(this->_double))
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void	Converter::convert(void) {
	checkInput(this->_input);
	if (this->_specialLiteral) {
		displayPrompt();
		return ;
	}
	switch (this->_inputType) {
		case 1:
			this->toChar(this->_input);
			break;
		case 2:
			this->toInt(this->_input);
			break;
		case 3:
			this->toFloat(this->_input);
			break;
		case 4:
			this->toDouble(this->_input);
			break;
	}
}

void	Converter::toChar(std::string &num) {
	this->_char = num[0];
	this->_int = static_cast<int>(this->_char);
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<double>(this->_char);
	displayPrompt();
}

void	Converter::toInt(std::string &num) {
	size_t i = 0;
	int	sign = 1;

	if (num[i] == '-') {
		sign *= -1;
		i++;
	}
	for (; i < num.size(); i++) {
		this->_int = this->_int * 10 + (num[i] - '0');
	}
	this->_int *= sign;
	if (this->_int >= 32 && this->_int <= 126)
		this->_char = this->_int;
	else
		this->_char = NON_DISPL;
	this->_float = static_cast<float>(this->_int);
	this->_double = static_cast<double>(this->_int);
	displayPrompt();
}

void	Converter::toFloat(std::string &num) {
	this->_float = atof(num.c_str());
	if (this->_float >= 32 && this->_float <= 126) // isprintable()
		this->_char = this->_float;
	else
		this->_char = NON_DISPL;
	this->_int = static_cast<int>(this->_float);
	this->_double = static_cast<double>(this->_float);
	displayPrompt();
}

void	Converter::toDouble(std::string &num) {
	this->_double = atof(num.c_str());
	if (this->_double >= 32 && this->_double <= 126) // isprintable()
		this->_char = this->_float;
	else
		this->_char = NON_DISPL;
	this->_int = static_cast<int>(this->_double);
	this->_float = static_cast<float>(this->_double);
	displayPrompt();
}
