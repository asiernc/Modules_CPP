/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:27:11 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/15 18:55:43 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : _dbPath("") {
	
}

BitcoinExchange::BitcoinExchange(std::string filepath) : _dbPath(filepath) {
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : _dbPath(src._dbPath) {
	this->_db = src._db;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src) {
	this->_db = src._db;
	
	std::map<std::string, float>::iterator it;
	for (it = this->_db.begin(); it != this->_db.end(); ++it) {
		this->_db[it->first] = it->second; 
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {
	
}

std::map<std::string, float>	BitcoinExchange::getDB(void) {
	return (this->_db);
}

void	BitcoinExchange::createDB(void) {
	std::ifstream	file(this->_dbPath);
    std::string		line;

    if (!file.is_open())
        throw openError();
	this->_db.clear();
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;
        float value;

        if (std::getline(ss, date, ',') && std::getline(ss, valueStr)) {
            date.erase(date.find_last_not_of(" \n\r\t")+1);
            valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));

            std::stringstream valueStream(valueStr);
            valueStream >> value;
			
            this->_db[date] = value;
        }
    }
	file.close();
	return ;
	//std::map<std::string, float>::iterator it;
	//for (it = this->_db.begin(); it != this->_db.end(); ++it)
	//	std::cout << "Clave (Fecha): " << it->first << ", Valor: " << it->second << std::endl; 
}

void	BitcoinExchange::convertRates(std::map<std::string, float> input) {
	std::map<std::string, float>::iterator it;
	for (it = input.begin(); it != input.end(); ++it) {
		// checkear fecha
		// checkear valor
		// obtener valor en fecha csv
		// imprimir resultado
		std::cout << "hola";
	}
}
