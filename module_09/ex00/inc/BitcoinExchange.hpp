/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:24:46 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/15 18:57:04 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float>	_db;
		std::string						_dbPath;

	public:
		BitcoinExchange(void);
		BitcoinExchange(std::string filepath);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange(void);

		void	createDB(void);
		void	convertRates(std::map<std::string, float> input);
		std::map<std::string, float> getDB(void);

		class openError : public std::exception {
			public:
				virtual const char *what(void) const throw () {
					return ("Is not posible open the file.");
				};
		};
};

