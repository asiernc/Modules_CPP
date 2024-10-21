/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:22:24 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/21 16:33:42 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Please use ./PmergeMe \"str of ints\"" << std::endl;
		return (1);
	}
	std::string	input = argv[1];
	PmergeMe one = PmergeMe(input.c_str());
	std::cout << "DEQUE CONTAINER ==> " << std::endl;
	one.runSortDeque();
	std::cout << "VECTOR CONTAINER ==> " << std::endl;
	one.runSortVector();
	return (0);
}

