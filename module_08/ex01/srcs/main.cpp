/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:03:25 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/08 21:50:21 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

# define MAX_SIZE 10000

int main( void ) {
	Span	test1(MAX_SIZE);
	srand(time(NULL));
	
	unsigned int min_value = INT_MIN;
	unsigned int max_value = UINT_MAX;
	
	for (int i = 0; i < MAX_SIZE; i++) {
		unsigned int random = rand() % (max_value - min_value + 1) + min_value;
		test1.addNumber(random);
	}
	unsigned int shortestSpan = test1.shortestSpan();
	unsigned int longestSpan = test1.longestSpan();
	test1.showArray();
	std::cout << "Shortest Span = " << shortestSpan << std::endl;
	std::cout << "Longest Span = " << longestSpan << std::endl;
	
	// TEST FILL RANDOM 

	std::cout << "\n\n\nTESTER 2" << std::endl;
	Span	test2(42);
	try {
		test2.fillRandom(42);
		unsigned int shortestSpan2 = test2.shortestSpan();
		unsigned int longestSpan2 = test2.longestSpan();
		std::cout << "Shortest Span = " << shortestSpan2 << std::endl;
		std::cout << "Longest Span = " << longestSpan2 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	// try {
	// 	myArray::iterator it = easyfind(arr0, 4);
	// 	int index = 0;
	// 	for (myArray::iterator i = arr0.begin(); i != it; i++) {
	// 		index++;
	// 	}
	// 	std::cout << "This value \'4\' was find in index: "  << index << std::endl;
	// }
	// catch (std::exception &e) {
	// 	std::cerr << "Error: " << e.what() << std::endl;
	// }

	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	return 0;
}
