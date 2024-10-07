/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:03:25 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/07 19:13:03 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"

void toUpper(std::string &str) {
	for (size_t i = 0; i < str.length(); ++i) {
		str[i] = std::toupper(str[i]);
	}
}

int main( void ) {
	int arr[5] = {1, 2, 3, 4, 5};

	std::cout << "Before iter: " << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Executing iter with multiply by two..." << std::endl;
	iter(arr, 5, multiply);
	std::cout << "After iter: " << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl << std::endl << std::endl;

	std::string arr2[3] = {"bcn", "creatures", "mowgly"};
	std::cout << "Before iter: " << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << arr2[i] << " --- ";
	}
	std::cout << std::endl;
	std::cout << "Executing iter with toUpper function..." << std::endl;
	iter(arr2, 3, toUpper);
	std::cout << "After iter: " << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << arr2[i] << " --- ";
	}
	std::cout << std::endl;
	return 0;
}
