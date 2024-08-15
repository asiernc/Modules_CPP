/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:28:32 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/15 10:24:02 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	std::fstream file;
	std::string	newFile = ".replace";
	if (argc != 4 || *argv[1] || *argv[2]) {
		std::cout << "Please use ./sedIsForLosers <filepath> <string1> <string2>" << std::endl;
	}
}