/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:27:11 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/21 13:49:18 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _input(""), _sizeInput(0) {
	
}

PmergeMe::PmergeMe(const std::string &expression)
	: _input(expression), _sizeInput(0) {
	
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
	std::cout << "AFTER " << std::endl;
	std::deque<unsigned int>::iterator it = _parsed.begin();
	it = _parsed.begin();
	for (; it != _parsed.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	// if (this->_parsed)
	// 	delete [] this->_parsed;
}

bool	PmergeMe::isValidUint(const std::string &str) {
	if (str.empty() || str.find("0x") != std::string::npos)
		return (false);
	for (size_t i = 0; i < str.size(); i++) {
		if (!(std::isdigit(str[i])) && ((i == 0) && (str[i] == '+' || str[i] == '-')))
			return (false);
	}
	return (true);
}

unsigned int		PmergeMe::strToUint(const std::string &str) {
	std::stringstream	ss(str);
	unsigned int		num;
	
	ss >> num;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("Invalid integer: " + str);
	return num;
}

int	PmergeMe::handleInputDeque(void) {

	std::stringstream	ss(this->_input);
	std::string			token;
	//std::deque<unsigned int>	parsed;

	while (ss >> token) {
		if (isValidUint(token)) {
			try {
				//int num = strToInt(token);
				//std::cout << "NUMMMM    " << num << std::endl;
				this->_parsed.push_back(strToUint(token));
			}
			catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
		else {
			std::cerr << "Invalid input = " << token << std::endl;
			return (1);
		}
	}
	this->_sizeInput = this->_parsed.size();

	std::cout << "BEFORE " << std::endl;
	std::deque<unsigned int>::iterator it = _parsed.begin();
	for (; it != _parsed.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	fordJohnsonSortDeque(this->_parsed);
	

	// Filling array ??
	// this->_arr = new unsigned int[this->_sizeInput];
	// std::deque<unsigned int>::iterator it2 = this->_parsed.begin();
	// for (size_t i = 0; i < this->_sizeInput; i++) {
	// 	this->_arr[i] = *it2;
	// 	it2++;
	// }

	// // TEST
	// // TEST
	// for (size_t i = 0; i < this->_sizeInput; i++)
	// 	std::cout << "NUM ARRAY = " << this->_parsed[i] << std::endl;
	// // TEST
	
	return (0);
}

void	PmergeMe::fordJohnsonSortDeque(std::deque<unsigned int> &deque) {
	if (deque.size() <= 1)
		return ;
	std::deque<unsigned int> leftDeque,	rightDeque;

	int mid = deque.size() / 2;
	for (int i = 0; i < mid; i++) {
		leftDeque.push_back(deque.front());
		deque.pop_front();
	}
	while (!this->_parsed.empty()) {
		rightDeque.push_back(deque.front());
		deque.pop_front();
	}
	fordJohnsonSortDeque(leftDeque);
	fordJohnsonSortDeque(rightDeque);

	mergeDeque(deque, leftDeque, rightDeque);
	
	while (!rightDeque.empty()) {
        insertDeque(deque, deque.size(), rightDeque.front());
        rightDeque.pop_front();
    }
}

void	PmergeMe::mergeDeque(std::deque<unsigned int> &mergeDeque,
	std::deque<unsigned int> &leftDeque, std::deque<unsigned int> &rightDeque) {
	
	while (!leftDeque.empty() && !rightDeque.empty()) {
		if (leftDeque.front() <= rightDeque.front()) {
			mergeDeque.push_back(leftDeque.front());
			leftDeque.pop_front();
		}
		else {
			mergeDeque.push_back(rightDeque.front());
			rightDeque.pop_front();
		}
	}
	while (!leftDeque.empty()) {
		mergeDeque.push_back(leftDeque.front());
		leftDeque.pop_front();
	}
	while (!rightDeque.empty()) {
		mergeDeque.push_back(rightDeque.front());
		rightDeque.pop_front();
	}
}

void	PmergeMe::insertDeque(std::deque<unsigned int> &deque, int size, unsigned int key) {
	
	std::deque<unsigned int> tmp;

	while (size > 0 && deque.back() > key) {
		tmp.push_back(deque.back());
		deque.pop_back();
		//size--;
	}
	deque.push_back(key);
	while (!tmp.empty()) {
		deque.push_back(tmp.front());
		tmp.pop_front();
	}
}

