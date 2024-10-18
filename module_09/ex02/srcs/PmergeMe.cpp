/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:27:11 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/18 12:34:30 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
	
}

PmergeMe::PmergeMe(std::string expression) {
	
}

PmergeMe::PmergeMe(const PmergeMe &src)  {
	*this = src;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src)
		*this = src;
	return (*this);
}

PmergeMe::~PmergeMe(void) {
	
}

