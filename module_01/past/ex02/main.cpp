/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:30:03 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/10 19:38:45 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << "Memory address of the string variable: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR: " << &stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << "__________________________________________________" << std::endl;
	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value held by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value held by stringREF: " << stringREF << std::endl;
	return (0);
}
