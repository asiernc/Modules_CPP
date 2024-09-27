/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:04:51 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/26 20:21:59 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		std::cerr << "Please use: ./cStyleCastConverter \"string literal\"" << std::endl;
	ScalarConverter::convert(argv[1]);
	return (0);
}