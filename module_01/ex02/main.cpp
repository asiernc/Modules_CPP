/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:03 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/04 09:47:35 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << "Memory address of the string variable: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR:      " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:      " << &stringREF << std::endl;
	std::cout << "__________________________________________________" << std::endl << std::endl;
	std::cout << "Value of the string variable:          " << str << std::endl;
	std::cout << "Value held by stringPTR:               " << *stringPTR << std::endl;
	std::cout << "value held by stringREF:               " << stringREF << std::endl;

	std::cout << "__________________________________________________" << std::endl << std::endl;
	str = "To change the value of the string variable";
	std::cout << "New value for str ==> " << str << std::endl;
	std::cout << "Value of the stringREF variable:          " << stringREF << std::endl;
	std::cout << "Value of the pointer variable:            " << *stringPTR << std::endl;
	return (0);
}
