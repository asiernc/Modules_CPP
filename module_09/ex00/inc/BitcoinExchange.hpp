/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:24:46 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/16 17:11:47 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <stdbool.h>

enum {
	WRONG_DATE,
	WRONG_MONTH,
	WRONG_DAY,
	NOT_EXISTS,
	VALUE_TO_HIGH
};

class BitcoinExchange {
	private:
		std::map<std::string, float>	_db;
		std::string						_dbPath;
		float			getRate(std::string date, float value);

	public:
		BitcoinExchange(void);
		BitcoinExchange(std::string filepath);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange(void);

		void	createDB(void);
		void	convertRates(std::string date, float input);
		std::map<std::string, float> getDB(void);

		class openError : public std::exception {
			public:
				virtual const char *what(void) const throw () {
					return ("Is not posible open the file.");
				};
		};

		class dbError : public std::exception {
			public:
				virtual const char *what(void) const throw () {
					return ("Impossible create database. Problems with the file...");
				};
		};
};

