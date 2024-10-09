/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:03:25 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/08 16:37:52 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

typedef std::array<int, 10>myArray;

int main( void ) {
	myArray arr0 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	for (int *it = arr0.begin(); it != arr0.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

	try {
		myArray::iterator it = easyfind(arr0, 4);
		int index = 0;
		for (myArray::iterator i = arr0.begin(); i != it; i++) {
			index++;
		}
		std::cout << "This value \'4\' was find in index: "  << index << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}
