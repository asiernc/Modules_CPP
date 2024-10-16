/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:22:24 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/15 18:54:38 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Utils.cpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Please use: ./btc filepath(second db)" << std::endl;
		return (1);
	}
	
	BitcoinExchange btcDB = BitcoinExchange("inputs/data.csv");
	try {
		btcDB.createDB();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::string	inputFilePath = argv[1];
	std::map<std::string, float> input = extractInput(inputFilePath.c_str());
	btcDB.convertRates(input);
}
