/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:27:11 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/21 17:20:11 by anovio-c         ###   ########.fr       */
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

int	RPN::strToInt(const std::string &ref) {
	std::stringstream	ss(ref);
	int					num = 0;
	ss >> num;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("Invalid integer: " + ref);
	return (num);
}

void RPN::handleInput(void) {
	std::stringstream ss(this->_expression);
	std::string		token;
	while (ss >> token) {
		if (token.size() == 1 && isOperator(token[0]))
			this->_parsed.push_back(static_cast<int>(token[0]));
		else {
			try {
                this->_parsed.push_back(strToInt(token));
            } catch (const std::invalid_argument &e) {
                std::cerr << e.what() << std::endl;
                throw badExpression();
            }			
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

