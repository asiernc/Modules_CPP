/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:03:25 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/17 12:25:54 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

# define MAX_SIZE 10000

int main( void ) {
	
	std::cout << "\n\n\nTESTER 1 ==> Custom test for user experience." << std::endl;
	Span	test1(MAX_SIZE);
	srand(time(NULL));
	
	// Allow yourself the luxury of modifying the following values.
	// Range ==> INT_MIN ~ UINT_MAX
	unsigned int min_value = 0;
	unsigned int max_value = 5000;
	
	for (int i = 0; i < MAX_SIZE; i++) {
		unsigned int random = rand() % (max_value - min_value + 1) + min_value;
		test1.addNumber(random);
	}
	test1.showArray();
	std::cout << "Shortest Span = " << test1.shortestSpan() << std::endl;
	std::cout << "Longest Span = " << test1.longestSpan() << std::endl;
	
	// TEST FILL RANDOM 

	std::cout << "\n\n\nTESTER 2 ==> Testing fillRandom function with all correct params." << std::endl;
	Span	test2(42);
	try {
		test2.fillRandom(42);
		std::cout << "Shortest Span = " << test2.shortestSpan() << std::endl;
		std::cout << "Longest Span = " << test2.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n\n\nTESTER 3 ==> adding number to Span size 0." << std::endl;
	Span	test3(0);
	try {
		test3.addNumber(2);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "\n\n\nTESTER 4 ==> adding more numbers than vector size." << std::endl;
	Span	test4(10);
	try {
		test4.addNumber(1);
		// Adding 1 number, of size 10, real size == 9, adding 10 random numbers == error. 
		// You can test adding only 9?
		test4.fillRandom(10);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n\n\nTESTER 5 ==> Calculate span with empty vector or size 1." << std::endl;
	Span	test5(0);
	try {
		test5.longestSpan();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	Span test6(1);
	try {
		test6.addNumber(42);
		test6.shortestSpan();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n\n\nTESTER 6 ==> Adding range of iterators." << std::endl;
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
	Span test7(5);

	try {
		test7.addRange(numbers.begin(), numbers.end());
		test7.showArray();
		std::cout << "Shortest Span = " << test7.shortestSpan() << std::endl;
		std::cout << "Longest Span = " << test7.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	Span test8(5);
	try {
		std::cout << "First fill vector with one number..." << std::endl;
		std::cout << "Later fill size 5 vector." << std::endl;
		test8.addNumber(1);
		test8.addRange(numbers.begin(), numbers.end());
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "See you soon!" << std::endl;
	return 0;
}
