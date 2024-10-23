/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:27:11 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/22 10:09:48 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _input("") {
	
}

PmergeMe::PmergeMe(const std::string &expression)
	: _input(expression) {
	
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

void	PmergeMe::printTime(timeval start, timeval end, int flag) {
	long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    long totalMicroseconds = seconds * 1000000 + microseconds;
	std::cout << "Time to process a range of " << this->_sizeInput << " elements with std::";
	if (flag == 0)
		std::cout << "deque : ";
	else
		std::cout << "vector : ";
	std::cout << totalMicroseconds << " us"  << std::endl;
}

void	PmergeMe::runSortDeque(void) {
	struct timeval start, end;
	
	try {
		handleInputDeque();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return ;
	}
	std::cout << "Before : \t";
	printDeque();
	gettimeofday(&start, NULL);
	fordJohnsonSortDeque(this->_parsedDeque);
	gettimeofday(&end, NULL);
	std::cout << "After : \t";
	printDeque();
	printTime(start, end, 0);
}

void	PmergeMe::runSortVector(void) {
	struct timeval start, end;
	
	try {
		handleInputVector();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return ;
	}
	std::cout << "Before : \t";
	printVector();
	gettimeofday(&start, NULL);
	fordJohnsonSortVector(this->_parsedVector);
	gettimeofday(&end, NULL);
	std::cout << "After : \t";
	printVector();
	printTime(start, end, 1);
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

	while (ss >> token) {
		if (isValidUint(token)) {
			try {
				this->_parsedDeque.push_back(strToUint(token));
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
	this->_sizeInput = this->_parsedDeque.size();
	return (0);
}

int	PmergeMe::handleInputVector(void) {

	std::stringstream	ss(this->_input);
	std::string			token;

	while (ss >> token) {
		if (isValidUint(token)) {
			try {
				this->_parsedVector.push_back(strToUint(token));
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
	this->_sizeInput = this->_parsedVector.size();
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
	while (!deque.empty()) {
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
							 std::deque<unsigned int> &leftDeque,
							 std::deque<unsigned int> &rightDeque) {
	
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
	}
	deque.push_back(key);
	while (!tmp.empty()) {
		deque.push_back(tmp.front());
		tmp.pop_front();
	}
}

void	PmergeMe::fordJohnsonSortVector(std::vector<unsigned int> &vector) {
	if (vector.size() <= 1)
		return ;
	std::vector<unsigned int> leftVector, rightVector;

	int mid = vector.size() / 2;
	for (int i = 0; i < mid; i++) {
		leftVector.push_back(vector.front());
		vector.erase(vector.begin());
	}
	while (!vector.empty()) {
		rightVector.push_back(vector.front());
		vector.erase(vector.begin());
	}
	fordJohnsonSortVector(leftVector);
	fordJohnsonSortVector(rightVector);

	mergeVector(vector, leftVector, rightVector);
	
	while (!rightVector.empty()) {
        insertVector(vector, vector.size(), rightVector.front());
		rightVector.erase(rightVector.begin());
    }
}

void	PmergeMe::mergeVector(std::vector<unsigned int> &mergeVector,
							 std::vector<unsigned int> &leftVector,
							 std::vector<unsigned int> &rightVector) {
	
	while (!leftVector.empty() && !rightVector.empty()) {
		if (leftVector.front() <= rightVector.front()) {
			mergeVector.push_back(leftVector.front());
			leftVector.erase(leftVector.begin());
		}
		else {
			mergeVector.push_back(rightVector.front());
			rightVector.erase(rightVector.begin());
		}
	}
	while (!leftVector.empty()) {
		mergeVector.push_back(leftVector.front());
		leftVector.erase(leftVector.begin());
	}
	while (!rightVector.empty()) {
		mergeVector.push_back(rightVector.front());
		rightVector.erase(rightVector.begin());
	}
}

void	PmergeMe::insertVector(std::vector<unsigned int> &vector, int size, unsigned int key) {
	std::vector<unsigned int> tmp;

	while (size > 0 && vector.back() > key) {
		tmp.push_back(vector.back());
		vector.pop_back();
	}
	vector.push_back(key);
	while (!tmp.empty()) {
		vector.push_back(tmp.front());
		tmp.erase(tmp.begin());
	}
}

void	PmergeMe::printDeque(void) {
	std::deque<unsigned int>::iterator it = this->_parsedDeque.begin();
	for (; it != this->_parsedDeque.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::printVector(void) {
	std::vector<unsigned int>::iterator it = this->_parsedVector.begin();
	for (; it != this->_parsedVector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
