/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:04:51 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/01 20:37:07 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"
# include "Converter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Please use: ./cStyleCastConverter \"string literal\"" << std::endl;
		return (1);
	}
	std::string	toConvert = argv[1];
	Converter input(toConvert);
	try {
		input.convert();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
