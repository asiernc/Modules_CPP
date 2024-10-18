/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:22:24 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/18 12:34:18 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Please use ./RPN \"inverted Polish mathematical expression\"" << std::endl;
		return (1);
	}
	
	return (0);
}

