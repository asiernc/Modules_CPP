/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:20:47 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/22 10:11:25 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <sys/time.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <stdbool.h>

class PmergeMe {
	private:
		std::string					_input;
		size_t						_sizeInput;
		std::vector<unsigned int>	_parsedVector;
		std::deque<unsigned int>	_parsedDeque;
		
		
		// Parsed
		int				handleInputDeque(void);
		int				handleInputVector(void);
		
		// Ford-Johnson Deque Algorithm
		void			fordJohnsonSortDeque(std::deque<unsigned int> &deque);
		void			mergeDeque(std::deque<unsigned int> &mergeDeque,
							std::deque<unsigned int> &leftDeque, std::deque<unsigned int> &rightDeque);
		void			insertDeque(std::deque<unsigned int> &deque, int size, unsigned int key);
		
		// Ford-Johnson Vector Algorithm
		void			fordJohnsonSortVector(std::vector<unsigned int> &vector);
		void			mergeVector(std::vector<unsigned int> &mergeVector,
							std::vector<unsigned int> &leftVector, std::vector<unsigned int> &rightVector);
		void			insertVector(std::vector<unsigned int> &vector, int size, unsigned int key);
	
		// Utils
		bool			isValidUint(const std::string &str);
		unsigned int	strToUint(const std::string &str);
		void			printTime(timeval start, timeval end, int flag);
		void			printDeque(void);
		void			printVector(void);
	
	public:
		PmergeMe(void);
		PmergeMe(const std::string &input);
		PmergeMe(const PmergeMe &src);
		PmergeMe	&operator=(const PmergeMe &src);
		~PmergeMe(void);

		
		void			runSortDeque(void);
		void			runSortVector(void);

		class badInput : public std::exception {
			public:
				virtual const char *what(void) const throw() {
					return ("Bad input... :\\");
				};
		};
};


// probar que suelta bien la exception del input 

