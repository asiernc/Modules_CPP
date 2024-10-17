/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:20:47 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/16 18:39:45 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <stdbool.h>



class RPN {
	private:
		std::string		_expression;
		std::list<int>	_parsed;
		static bool validChars(char c) {
			return (c == '+' || c == '-' || c == '*' || c == '/' || c == ' ' || (c >= '0' && c <= '9'));
		}

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
