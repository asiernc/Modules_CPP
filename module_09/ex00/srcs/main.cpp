/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:22:24 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/23 09:30:47 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Utils.hpp"


int main(int argc, char **argv) {
	if (argc < 2 || argc > 3) {
		std::cerr << "Please use: ./btc filepath(toConvert)\n\tOPTIONAL 3rd argv: filepath(database)" << std::endl;
		return (1);
	}
	std::string	dbPath = "inputs/data.csv";
	if (argv[2])
		dbPath = argv[2];
	BitcoinExchange btcDB = BitcoinExchange(dbPath);
	try {
		btcDB.createDB();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	std::string	inputFilePath = argv[1];
	try {
		extractInput(btcDB, inputFilePath.c_str());
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}

