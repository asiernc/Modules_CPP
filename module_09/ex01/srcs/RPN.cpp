/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:27:11 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/16 19:00:17 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) : _expression("") {
	
}

RPN::RPN(std::string expression) : _expression(expression) {
	
}

RPN::RPN(const RPN &src)  {
	*this = src;
}

RPN	&RPN::operator=(const RPN &src) {
	if (this != &src)
		*this = src;
	return (*this);
}

RPN::~RPN(void) {
	
}

void RPN::handleInput(void) {
    int flagSpace = 1;
    std::string numberStr;

    for (size_t i = 0; i < this->_expression.size(); i++) {
        char currentChar = this->_expression[i];

        if (validChars(currentChar)) {
            if (currentChar >= '0' && currentChar <= '9') {
                if (flagSpace == 0)
					throw badExpression();
				_parsed.push_back(currentChar - '0');
				flagSpace = 0;
            } 
            else if (currentChar == ' ')
                flagSpace = 1;
            else {
                if (flagSpace == 0)
					flagSpace = 1;
                _parsed.push_back(static_cast<int>(currentChar));
            }
        } else {
            throw badExpression();
        }
    }
}

si tengo un numero, buscar automaticamente el siguiente operador, y eliminarlo


void	RPN::calculate(void) {
	if (this->_parsed.size() < 3) {
		throw badExpression();
		return ;
	}
	std::list<int>::iterator it = this->_parsed.begin();
	int accum = *it;
	++it;
	for (; it != this->_parsed.end(); ++it) {
        int currentValue = *it;
        ++it;
        char operatorChar = static_cast<char>(*it);
        if (it == this->_parsed.end()) {
            throw badExpression(); // operand after operator
        }
        //std::cout << "CURRENT " << currentValue << "   OPERATOR " << operatorChar << std::endl; 

        switch (operatorChar) {
            case '+':
                accum += currentValue;
                break;
            case '-':
                accum -= currentValue;
                break;
            case '*':
                accum *= currentValue;
                break;
            case '/':
                //if (currentValue == 0) {
                //    throw badExpression();
                //}
                accum /= currentValue;
                break;
            default:
                throw badExpression();
        }
    }
    std::cout << "Result: " << accum << std::endl;
}

