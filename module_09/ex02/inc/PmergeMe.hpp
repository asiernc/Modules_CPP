/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:20:47 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/21 13:24:59 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <deque>
#include <stdbool.h>

class PmergeMe {
	private:
		std::string					_input;
		size_t						_sizeInput;
		unsigned int				*_arr;
		std::vector<unsigned int>	_unsortVector;
		std::deque<unsigned int>	_unsortDeque;
		std::deque<unsigned int>	_parsed;
		bool						isValidUint(const std::string &str);
		unsigned int				strToUint(const std::string &str);
	public:
		PmergeMe(void);
		PmergeMe(const std::string &input);
		PmergeMe(const PmergeMe &src);
		PmergeMe	&operator=(const PmergeMe &src);
		~PmergeMe(void);

		std::deque<unsigned int>	getDeque(void) const;
		int		handleInputDeque(void);
		void	fordJohnsonSortDeque(std::deque<unsigned int> &deque);
		void	mergeDeque(std::deque<unsigned int> &mergeDeque,
			std::deque<unsigned int> &leftDeque, std::deque<unsigned int> &rightDeque);
		void	insertDeque(std::deque<unsigned int> &deque, int size, unsigned int key);
};
