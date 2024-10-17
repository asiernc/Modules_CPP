/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:22:24 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/16 18:39:26 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		std::cerr << "Please use ./RPN \"inverted Polish mathematical expression\"" << std::endl;
	std::string	expr = argv[1];
	RPN	rpn(expr.c_str());
	try {
		rpn.handleInput();
		rpn.calculate();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}
