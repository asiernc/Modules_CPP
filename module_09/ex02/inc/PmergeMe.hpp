/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:20:47 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/21 16:32:25 by anovio-c         ###   ########.fr       */
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
		bool						isValidUint(const std::string &str);
		unsigned int				strToUint(const std::string &str);
		void	printDeque(void);
		void	printVector(void);
		void	printTime(timeval start, timeval end, int flag);
	public:
		PmergeMe(void);
		PmergeMe(const std::string &input);
		PmergeMe(const PmergeMe &src);
		PmergeMe	&operator=(const PmergeMe &src);
		~PmergeMe(void);

		std::deque<unsigned int>	getDeque(void) const;

		// Ford-Johnson Deque Algorithm
		
		int		handleInputDeque(void);
		int		handleInputVector(void);
		void	runSortDeque(void);
		void	runSortVector(void);
		void	fordJohnsonSortDeque(std::deque<unsigned int> &deque);
		void	mergeDeque(std::deque<unsigned int> &mergeDeque,
			std::deque<unsigned int> &leftDeque, std::deque<unsigned int> &rightDeque);
		void	insertDeque(std::deque<unsigned int> &deque, int size, unsigned int key);
		void	fordJohnsonSortVector(std::vector<unsigned int> &vector);
		void	mergeVector(std::vector<unsigned int> &mergeVector,
			std::vector<unsigned int> &leftVector, std::vector<unsigned int> &rightVector);
		void	insertVector(std::vector<unsigned int> &vector, int size, unsigned int key);

		// Ford-Johnson Vector Algorithm
};
