/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:27:11 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/17 15:35:35 by anovio-c         ###   ########.fr       */
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
	std::ifstream	file(this->_dbPath.c_str());
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
	if (this->_db.empty())
		throw dbError();
	return ;
}


float	BitcoinExchange::getRate(std::string date, float value) {
	std::map<std::string, float>::iterator it = this->_db.find(date);

	// fecha exacta
    if (it != this->_db.end()) {
        return (value * it->second);
    }

    // Si no se encuentra la fecha exacta, buscamos la más cercana
    it = this->_db.lower_bound(date);
    if (it == this->_db.end()) {
        if (this->_db.empty()) {
            std::cerr << "Error: No data available for conversion." << std::endl;
            return 0.0f;
        }
        // Si no hay una fecha mayor o igual, usamos la última fecha disponible
        --it;
        return (value * it->second);
    }

    // Si lower_bound devolvió un iterador válido pero no es la fecha exacta, 
    // retrocedemos al iterador anterior (la fecha más cercana anterior)
    if (it != this->_db.begin()) {
        --it;
    }
    return (value * it->second);
}

void	BitcoinExchange::convertRates(std::string date, float value) {
	float valueConverted = getRate(date, value);
	std::cout << date << " ==> " << value << " = "
		<< valueConverted << std::endl;
}
