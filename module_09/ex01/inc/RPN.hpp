/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:20:47 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/21 17:12:03 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <stack>
#include <stdbool.h>



class RPN {
	private:
		std::string		_expression;
		std::list<int>	_parsed;
		static bool validChars(char c) {
			return (c == '+' || c == '-' || c == '*' || c == '/' || c == ' ' || (c >= '0' && c <= '9'));
		}
		static bool	isOperator(int value) {
			return (value == '+' || value == '-' || value == '*' || value == '/');
		}
		int	strToInt(const std::string &ref);

	public:
		RPN(void);
		RPN(std::string algo);
		RPN(const RPN &src);
		RPN	&operator=(const RPN &src);
		~RPN(void);

		void	handleInput(void);
		void	calculate(void);

		class badExpression : public std::exception {
			public:
				virtual const char *what(void) const throw() {
					return ("Error: bad expression."); 
				};
		};
};
