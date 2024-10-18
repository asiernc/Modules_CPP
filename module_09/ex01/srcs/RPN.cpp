/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:27:11 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/18 12:30:54 by anovio-c         ###   ########.fr       */
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

void	RPN::calculate(void) {
	if (this->_parsed.size() < 3) {
		throw badExpression();
		return ;
	}
	std::list<int>::iterator it = this->_parsed.begin();
	std::stack<int> opeStack;
	while (it != this->_parsed.end()) {
		if (*it > 10) {
			if (opeStack.size() < 2)
				throw badExpression();
			int right = opeStack.top();
			opeStack.pop();
			int left = opeStack.top();
			opeStack.pop();
			char operatorChar = static_cast<char>(*it);
			switch (operatorChar) {
				case '+':
					opeStack.push(left + right);
					break ;
				case '-':
					opeStack.push(left - right);
					break ;
				case '*':
					opeStack.push(left * right);
					break ;
				case '/':
					if (right == 0)
						throw badExpression();
                    opeStack.push(left / right);
                    break;
				default:
					throw badExpression();
			}
		}
		else
			opeStack.push(*it);
		++it;
	}
	if (opeStack.size() != 1)
		throw badExpression();
    std::cout << "Result: " << opeStack.top() << std::endl;
}

