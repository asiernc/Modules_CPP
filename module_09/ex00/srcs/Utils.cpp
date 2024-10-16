/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:43:28 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/15 18:59:46 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "BitcoinExchange.hpp"

// checkear aqui date y value 

std::map<std::string, float>	extractInput(std::string inputPath) {
	std::map<std::string, float>	parsed;
	std::ifstream					file(inputPath);
	std::string						line;

	if (!file.is_open())
		throw BitcoinExchange::openError();
	while (std::getline(file, line)) {
		std::stringstream	ss(line);
		std::string			date;
		std::string			valueStr;
		float				value;
		if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
			date.erase(date.find_last_not_of(" \n\r\t") + 1);
			valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));
			
			std::stringstream valueStream(valueStr);
			valueStream >> value;
			parsed[date] = value;
		}
	}
	std::map<std::string, float>::iterator it;
	for (it = parsed.begin(); it != parsed.end(); ++it)
		std::cout << "Clave (Fecha): " << it->first << ", Valor: " << it->second << std::endl; 
	file.close();
	return (parsed);
}
