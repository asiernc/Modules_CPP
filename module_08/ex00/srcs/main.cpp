/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:03:25 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/17 11:54:32 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"


int main( void ) {
	std::vector<int> test;
	
	for (int i = 0; i < 10; ++i) {
		test.push_back(i);
	}
	std::vector<int>::iterator it = test.begin();
	for (; it != test.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

	try {
		easyfind(test, 4);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
