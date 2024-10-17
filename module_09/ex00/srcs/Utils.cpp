/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:43:28 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/16 17:14:59 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

static void	sendError(int code, std::string date) {
	std::cerr << "Error: ";
	switch (code) {
	case WRONG_DATE:
		std::cerr << "Bad input ==> " << date << std::endl;
		break;
	case WRONG_MONTH:
		std::cerr << "That month not exists... ==> " << date << std::endl;
		break;
	case WRONG_DAY:
		std::cerr << "That day not exists in that month... ==> " << date << std::endl;
		break;
	case NOT_EXISTS:
		std::cerr << "One moment.. if you had btc before that date... are you Satoshi Nakamoto? ==> " << date << std::endl;
		break;
	case VALUE_TO_HIGH:
		std::cerr << date << std::endl;
		break;
	default:
		break;
	}
}

static bool	isLeapYear(int	year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static bool	checkDate(std::string str) {
	// se podria haber recorrido map db it->first comparar y si no esta pa fuera!
	int daysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int	year;
	int	month;
	int	day;
	int counter = 0;

	for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == '-')
			counter++;
	}
	if (counter != 2 && str.size() != 10) {
		sendError(WRONG_DATE, str);
		return (false);
	}
	try {
		year = std::stoi(str.substr(0, 4));
		month = std::stoi(str.substr(5, 2));
		day = std::stoi(str.substr(8, 2));
	}
	catch (const std::invalid_argument &e) {
		sendError(WRONG_DATE, str);
		return (false);
	}
	if (year < 2009 && (year == 2009 && month == 1 && day < 3)) {
		sendError(NOT_EXISTS, str);
		return (false);
	}
	if (month < 1 || month > 12) {
		sendError(WRONG_MONTH, str);
		return (false);
	}
	if (isLeapYear(year))
		daysMonth[2] = 29;
	if (day < 1 || day > daysMonth[month - 1]) {
		sendError(WRONG_DAY, str);
		return (false);
	}
	return (true);
}

static bool	checkValue(float value) {
	if (value < 0) {
		sendError(VALUE_TO_HIGH, "Negative value not allowed.");
		return (false);
	}
	if (value > 1000) {
        sendError(VALUE_TO_HIGH, "Value exceeds maximum limit.");
        return (false);
    }
	return (true);
}

void	extractInput(BitcoinExchange btcDB, std::string inputPath) {
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
			if (!checkDate(date)) continue ;
			valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));
			std::stringstream valueStream(valueStr);
			if (!(valueStream >> value)) {
				sendError(VALUE_TO_HIGH, NULL);
				continue;
			}
			if (!checkValue(value)) continue;
			btcDB.convertRates(date, value);
		}
		else
			sendError(WRONG_DATE, date);
	}
	file.close();
	return ;
}
